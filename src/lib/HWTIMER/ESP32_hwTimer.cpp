
#ifdef PLATFORM_ESP32
#include "ESP32_hwTimer.h"
#include "logging.h"

static hw_timer_t *timer = NULL;
static portMUX_TYPE isrMutex = portMUX_INITIALIZER_UNLOCKED;

void hwTimer::nullCallback(void) {}
void (*hwTimer::callbackTick)() = &nullCallback;
void (*hwTimer::callbackTock)() = &nullCallback;

volatile uint32_t hwTimer::HWtimerInterval = TimerIntervalUSDefault;
volatile bool hwTimer::isTick = false;
volatile int32_t hwTimer::PhaseShift = 0;
volatile int32_t hwTimer::FreqOffset = 0;
volatile bool hwTimer::running = false;
uint32_t hwTimer::NextTimeout;

#define HWTIMER_TICKS_PER_US 5
#define HWTIMER_PRESCALER (clockCyclesPerMicrosecond() / HWTIMER_TICKS_PER_US)


void ICACHE_RAM_ATTR hwTimer::init()
{
    if (!timer)
    {
        timer = timerBegin(0, (APB_CLK_FREQ / 1000000), true); // us timer
        timerAttachInterrupt(timer, &callback, true);
        timerAlarmWrite(timer, HWtimerInterval, false);
        running = false;
        DBGLN("hwTimer Init");
    }
}

void ICACHE_RAM_ATTR hwTimer::stop()
{
    if (timer)
    {
        running = false;
        timerAlarmDisable(timer);
        DBGLN("hwTimer stop");
    }
}

void ICACHE_RAM_ATTR hwTimer::resume()
{
    if (timer)
    {
        running = true;
        timerAlarmWrite(timer, HWtimerInterval, false);
        timerAlarmEnable(timer);
        DBGLN("hwTimer resume");
    }
}

void ICACHE_RAM_ATTR hwTimer::updateInterval(uint32_t newTimerInterval)
{
#if 0
    HWtimerInterval = time;
    if (timer)
    {
        DBGLN("hwTimer interval: %d", time);
        timerAlarmWrite(timer, HWtimerInterval, false);
    }
#else
    // timer should not be running when updateInterval() is called
    hwTimer::HWtimerInterval = newTimerInterval * (HWTIMER_TICKS_PER_US * HWTIMER_PRESCALER);
#endif
}

void ICACHE_RAM_ATTR hwTimer::resetFreqOffset()
{
    FreqOffset = 0;
}

void ICACHE_RAM_ATTR hwTimer::incFreqOffset()
{
    FreqOffset++;
}

void ICACHE_RAM_ATTR hwTimer::decFreqOffset()
{
    FreqOffset--;
}

void ICACHE_RAM_ATTR hwTimer::phaseShift(int32_t newPhaseShift)
{
    int32_t minVal = -(hwTimer::HWtimerInterval >> 2);
    int32_t maxVal = (hwTimer::HWtimerInterval >> 2);

    // phase shift is in microseconds
    hwTimer::PhaseShift = constrain(newPhaseShift, minVal, maxVal) * (HWTIMER_TICKS_PER_US * HWTIMER_PRESCALER);
}

void ICACHE_RAM_ATTR hwTimer::callback(void)
{
    portENTER_CRITICAL_ISR(&isrMutex);
    if (running)
    {
        NextTimeout += (hwTimer::HWtimerInterval >> 1) + (FreqOffset * HWTIMER_PRESCALER);
        if (hwTimer::isTick)
        {
//            timer0_write(NextTimeout);
            timerAlarmWrite(timer, NextTimeout, false);
            hwTimer::callbackTick();
        }
        else
        {
            NextTimeout += hwTimer::PhaseShift;
//            timer0_write(NextTimeout);
            timerAlarmWrite(timer, NextTimeout, false);
            hwTimer::PhaseShift = 0;
            hwTimer::callbackTock();
        }
        hwTimer::isTick = !hwTimer::isTick;
    }
    portEXIT_CRITICAL_ISR(&isrMutex);
}

#endif
