// The name of the device in the LUA module
#define DEVICE_NAME "PK HAWK 400 TX"

// Any device features
#define USE_OLED_I2C

// Output Power
#define MinPower PWR_10mW
#define MaxPower PWR_100mW
#define POWER_OUTPUT_VALUES {8,12,15,18}

// GPIO pin definitions - Verified
#define GPIO_PIN_LED 16
#define GPIO_PIN_STROBE_LED 13
#define GPIO_PIN_BUTTON 0
//#define GPIO_PIN_BUZZER 1
//#define GPIO_PIN_PWM_OUTPUTS    {15, 14, 12, 11, 10, 9, 8, 7}

#define GPIO_PIN_NSS 36
//#define GPIO_PIN_DIO0 4
#define GPIO_PIN_DIO1 2
#define GPIO_PIN_DIO2 3
#define GPIO_PIN_MOSI 38
#define GPIO_PIN_MISO 39
#define GPIO_PIN_SCK 37
//#define GPIO_PIN_RST 2

//#define GPIO_PIN_RCSIGNAL_RX -1 //only uses default uart pins so leave as -1
//#define GPIO_PIN_RCSIGNAL_TX -1
#define GPIO_PIN_RCSIGNAL_RX 14
#define GPIO_PIN_RCSIGNAL_TX 15

#define GPIO_PIN_OLED_SDA 34
#define GPIO_PIN_OLED_SCK 33
#define GPIO_PIN_OLED_RST U8X8_PIN_NONE

// GPIO pin definitions - TODO
#ifdef USE_DIVERSITY
    #define GPIO_PIN_ANTENNA_SELECT 9
#endif

