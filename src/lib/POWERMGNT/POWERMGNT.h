#pragma once

#include "options.h"

#if defined(PLATFORM_ESP32)
#include <nvs_flash.h>
#include <nvs.h>
#endif

#ifndef POWER_OUTPUT_VALUES
    // These are "fake" values as the power on the RX is not user selectable
    #define MinPower PWR_10mW
    #define MaxPower PWR_10mW
#endif

#if !defined(DefaultPower)
    #define DefaultPower PWR_50mW
#endif

#if defined(Regulatory_Domain_EU_CE_2400)
    #undef MaxPower
    #define MaxPower PWR_100mW

    #if defined(HighPower)
        #undef HighPower
        #define HighPower MaxPower
    #endif
#endif

#if !defined(HighPower)
#define HighPower MaxPower
#endif

typedef enum
{
    PWR_10mW = 0,
    PWR_25mW = 1,
    PWR_50mW = 2,
    PWR_100mW = 3,
    PWR_250mW = 4,
    PWR_500mW = 5,
    PWR_1000mW = 6,
    PWR_2000mW = 7,
    PWR_COUNT = 8
} PowerLevels_e;

class PowerLevelContainer
{
protected:
    static PowerLevels_e CurrentPower;
public:
    static PowerLevels_e currPower() { return CurrentPower; }
};

#ifndef UNIT_TEST

class POWERMGNT : public PowerLevelContainer
{

private:
    static int8_t CurrentSX1280Power;
    static PowerLevels_e FanEnableThreshold;
    static void updateFan();
#if defined(PLATFORM_ESP32)
    static nvs_handle  handle;
#endif
    static void LoadCalibration();

public:
    static void setPower(PowerLevels_e Power);
    static PowerLevels_e incPower();
    static PowerLevels_e decPower();
    static PowerLevels_e currPower() { return CurrentPower; }
    static PowerLevels_e getMinPower() { return MinPower; }
    static PowerLevels_e getMaxPower() {
        #if defined(TARGET_RX)
            return MaxPower;
        #else
            return firmwareOptions.unlock_higher_power ? MaxPower : HighPower;
        #endif
    }
    static void incSX1280Ouput();
    static void decSX1280Ouput();
    static int8_t currentSX1280Ouput();
    static PowerLevels_e getDefaultPower();
    static uint8_t getPowerIndBm();
    static void setDefaultPower();
    static void init();
    static void SetPowerCaliValues(int8_t *values, size_t size);
    static void GetPowerCaliValues(int8_t *values, size_t size);
};


#define CALIBRATION_MAGIC    0x43414C << 8   //['C', 'A', 'L']
#define CALIBRATION_VERSION   1

#endif /* !UNIT_TEST */
