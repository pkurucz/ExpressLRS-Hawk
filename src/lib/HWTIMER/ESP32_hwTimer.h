#pragma once

#include <stdio.h>
#include "targets.h"

#define TimerIntervalUSDefault 4000

class hwTimer
{
public:
	static volatile uint32_t HWtimerInterval;
	static volatile bool isTick;
	static volatile int32_t PhaseShift;
	static volatile int32_t FreqOffset;
	static volatile bool running;
	static uint32_t NextTimeout;

	static void init();
	static void ICACHE_RAM_ATTR stop();
	static void ICACHE_RAM_ATTR resume();
	static void ICACHE_RAM_ATTR callback();
	static void ICACHE_RAM_ATTR updateInterval(uint32_t newTimerInterval = TimerIntervalUSDefault);
	static void resetFreqOffset();
	static void incFreqOffset();
	static void decFreqOffset();
	static void phaseShift(int32_t newPhaseShift);

	static void ICACHE_RAM_ATTR nullCallback(void);
	static void (*callbackTick)();
	static void (*callbackTock)();
};
