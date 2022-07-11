#include "targets.h"
#include "common.h"
#include "device.h"

#if defined(GPIO_PIN_BUTTON)
#include "logging.h"
#include "button.h"

static Button button;

#ifndef GPIO_BUTTON_INVERTED
#define GPIO_BUTTON_INVERTED false
#endif

#if defined(TARGET_TX)
#include "POWERMGNT.h"
void EnterBindingMode();

static void enterBindMode3Click()
{
    if (button.getCount() == 3)
    {
        EnterBindingMode();
    }
};

static void cyclePower()
{
    // Only change power if we are running normally
    if (connectionState < MODE_STATES)
    {
        PowerLevels_e curr = POWERMGNT::currPower();
        if (curr == POWERMGNT::getMaxPower())
        {
            POWERMGNT::setPower(POWERMGNT::getMinPower());
        }
        else
        {
            POWERMGNT::incPower();
        }
        devicesTriggerEvent();
    }
};
#endif

#if defined(TARGET_RX) && (defined(PLATFORM_ESP32) || defined(PLATFORM_ESP8266))
static void rxWebUpdateReboot()
{
    if (button.getLongCount() > 4 && connectionState != wifiUpdate)
    {
        connectionState = wifiUpdate;
    }
    if (button.getLongCount() > 8)
    {
        ESP.restart();
    }
};
#endif

static void initialize()
{
    if (GPIO_PIN_BUTTON != UNDEF_PIN)
    {
        button.init(GPIO_PIN_BUTTON, GPIO_BUTTON_INVERTED);
        #if defined(TARGET_TX)
            button.OnShortPress = enterBindMode3Click;
            button.OnLongPress = cyclePower;
        #endif
        #if defined(TARGET_RX) && (defined(PLATFORM_ESP32) || defined(PLATFORM_ESP8266))
            button.OnLongPress = rxWebUpdateReboot;
        #endif
    }
}

static int start()
{
    if (GPIO_PIN_BUTTON == UNDEF_PIN)
    {
        return DURATION_NEVER;
    }
    return DURATION_IMMEDIATELY;
}

static int timeout()
{
    if (GPIO_PIN_BUTTON == UNDEF_PIN)
    {
        return DURATION_NEVER;
    }
    return button.update();
}

device_t Button_device = {
    .initialize = initialize,
    .start = start,
    .event = NULL,
    .timeout = timeout
};

#endif