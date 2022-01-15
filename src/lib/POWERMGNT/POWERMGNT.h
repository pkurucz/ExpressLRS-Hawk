#pragma once

#include "targets.h"
#include "DAC.h"

#include "RadioDriver.h"

#if defined(PLATFORM_ESP32)
#include <nvs_flash.h>
#include <nvs.h>
#endif

#if defined(TARGET_RX) && ( !defined(MinPower) || !defined(MaxPower) )
    // These are "fake" values as the power on the RX is not user selectable
	#undef MinPower
    #define MinPower PWR_10mW
	#undef MaxPower
    #define MaxPower PWR_10mW
#endif

#if defined(HighPower) && !defined(UNLOCK_HIGHER_POWER)
    #undef MaxPower
    #define MaxPower HighPower
#endif

#if !defined(DefaultPower)
    #define DefaultPower PWR_50mW
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

class POWERMGNT
{

private:
    static PowerLevels_e CurrentPower;
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
    static PowerLevels_e currPower();
    static uint8_t powerToCrsfPower(PowerLevels_e Power);
    static PowerLevels_e getDefaultPower();
    static void setDefaultPower();
    static void setFanEnableTheshold(PowerLevels_e Power);
    static void init();
    static void SetPowerCaliValues(int8_t *values, size_t size);
    static void GetPowerCaliValues(int8_t *values, size_t size);
};


#define CALIBRATION_MAGIC    0x43414C << 8   //['C', 'A', 'L']
#define CALIBRATION_VERSION   1
