#pragma once

/* Register defines borrowed from the RadioLib project: */
/* RadioLib/src/modules/SX126x/SX126x.h                 */

// SX126X physical layer properties
#define RADIOLIB_SX126X_FREQUENCY_STEP_SIZE                    0.9536743164
#define RADIOLIB_SX126X_MAX_PACKET_LENGTH                      255
#define RADIOLIB_SX126X_CRYSTAL_FREQ                           32.0
#define RADIOLIB_SX126X_DIV_EXPONENT                           25

// SX126X SPI commands
// operational modes commands
#define SX126X_CMD_NOP                                0x00
#define SX126X_CMD_SET_SLEEP                          0x84
#define SX126X_CMD_SET_STANDBY                        0x80
#define SX126X_CMD_SET_FS                             0xC1
#define SX126X_CMD_SET_TX                             0x83
#define SX126X_CMD_SET_RX                             0x82
#define SX126X_CMD_STOP_TIMER_ON_PREAMBLE             0x9F
#define SX126X_CMD_SET_RX_DUTY_CYCLE                  0x94
#define SX126X_CMD_SET_CAD                            0xC5
#define SX126X_CMD_SET_TX_CONTINUOUS_WAVE             0xD1
#define SX126X_CMD_SET_TX_INFINITE_PREAMBLE           0xD2
#define SX126X_CMD_SET_REGULATOR_MODE                 0x96
#define SX126X_CMD_CALIBRATE                          0x89
#define SX126X_CMD_CALIBRATE_IMAGE                    0x98
#define SX126X_CMD_SET_PA_CONFIG                      0x95
#define SX126X_CMD_SET_RX_TX_FALLBACK_MODE            0x93

// register and buffer access commands
#define SX126X_CMD_WRITE_REGISTER                     0x0D
#define SX126X_CMD_READ_REGISTER                      0x1D
#define SX126X_CMD_WRITE_BUFFER                       0x0E
#define SX126X_CMD_READ_BUFFER                        0x1E

// DIO and IRQ control
#define SX126X_CMD_SET_DIO_IRQ_PARAMS                 0x08
#define SX126X_CMD_GET_IRQ_STATUS                     0x12
#define SX126X_CMD_CLEAR_IRQ_STATUS                   0x02
#define SX126X_CMD_SET_DIO2_AS_RF_SWITCH_CTRL         0x9D
#define SX126X_CMD_SET_DIO3_AS_TCXO_CTRL              0x97

// RF, modulation and packet commands
#define SX126X_CMD_SET_RF_FREQUENCY                   0x86
#define SX126X_CMD_SET_PACKET_TYPE                    0x8A
#define SX126X_CMD_GET_PACKET_TYPE                    0x11
#define SX126X_CMD_SET_TX_PARAMS                      0x8E
#define SX126X_CMD_SET_MODULATION_PARAMS              0x8B
#define SX126X_CMD_SET_PACKET_PARAMS                  0x8C
#define SX126X_CMD_SET_CAD_PARAMS                     0x88
#define SX126X_CMD_SET_BUFFER_BASE_ADDRESS            0x8F
#define SX126X_CMD_SET_LORA_SYMB_NUM_TIMEOUT          0xA0

// status commands
#define SX126X_CMD_GET_STATUS                         0xC0
#define SX126X_CMD_GET_RSSI_INST                      0x15
#define SX126X_CMD_GET_RX_BUFFER_STATUS               0x13
#define SX126X_CMD_GET_PACKET_STATUS                  0x14
#define SX126X_CMD_GET_DEVICE_ERRORS                  0x17
#define SX126X_CMD_CLEAR_DEVICE_ERRORS                0x07
#define SX126X_CMD_GET_STATS                          0x10
#define SX126X_CMD_RESET_STATS                        0x00


// SX126X register map
#define RADIOLIB_SX126X_REG_WHITENING_INITIAL_MSB              0x06B8
#define RADIOLIB_SX126X_REG_WHITENING_INITIAL_LSB              0x06B9
#define RADIOLIB_SX126X_REG_CRC_INITIAL_MSB                    0x06BC
#define RADIOLIB_SX126X_REG_CRC_INITIAL_LSB                    0x06BD
#define RADIOLIB_SX126X_REG_CRC_POLYNOMIAL_MSB                 0x06BE
#define RADIOLIB_SX126X_REG_CRC_POLYNOMIAL_LSB                 0x06BF
#define RADIOLIB_SX126X_REG_SYNC_WORD_0                        0x06C0
#define RADIOLIB_SX126X_REG_SYNC_WORD_1                        0x06C1
#define RADIOLIB_SX126X_REG_SYNC_WORD_2                        0x06C2
#define RADIOLIB_SX126X_REG_SYNC_WORD_3                        0x06C3
#define RADIOLIB_SX126X_REG_SYNC_WORD_4                        0x06C4
#define RADIOLIB_SX126X_REG_SYNC_WORD_5                        0x06C5
#define RADIOLIB_SX126X_REG_SYNC_WORD_6                        0x06C6
#define RADIOLIB_SX126X_REG_SYNC_WORD_7                        0x06C7
#define RADIOLIB_SX126X_REG_NODE_ADDRESS                       0x06CD
#define RADIOLIB_SX126X_REG_BROADCAST_ADDRESS                  0x06CE
#define RADIOLIB_SX126X_REG_LORA_SYNC_WORD_MSB                 0x0740
#define RADIOLIB_SX126X_REG_LORA_SYNC_WORD_LSB                 0x0741
#define RADIOLIB_SX126X_REG_RANDOM_NUMBER_0                    0x0819
#define RADIOLIB_SX126X_REG_RANDOM_NUMBER_1                    0x081A
#define RADIOLIB_SX126X_REG_RANDOM_NUMBER_2                    0x081B
#define RADIOLIB_SX126X_REG_RANDOM_NUMBER_3                    0x081C
#define RADIOLIB_SX126X_REG_RX_GAIN                            0x08AC
#define RADIOLIB_SX126X_REG_OCP_CONFIGURATION                  0x08E7
#define RADIOLIB_SX126X_REG_XTA_TRIM                           0x0911
#define RADIOLIB_SX126X_REG_XTB_TRIM                           0x0912

// undocumented registers
#define RADIOLIB_SX126X_REG_SENSITIVITY_CONFIG                 0x0889 // SX1268 datasheet v1.1, section 15.1
#define RADIOLIB_SX126X_REG_TX_CLAMP_CONFIG                    0x08D8 // SX1268 datasheet v1.1, section 15.2
#define RADIOLIB_SX126X_REG_RTC_STOP                           0x0920 // SX1268 datasheet v1.1, section 15.3
#define RADIOLIB_SX126X_REG_RTC_EVENT                          0x0944 // SX1268 datasheet v1.1, section 15.3
#define RADIOLIB_SX126X_REG_IQ_CONFIG                          0x0736 // SX1268 datasheet v1.1, section 15.4
#define RADIOLIB_SX126X_REG_RX_GAIN_RETENTION_0                0x029F // SX1268 datasheet v1.1, section 9.6
#define RADIOLIB_SX126X_REG_RX_GAIN_RETENTION_1                0x02A0 // SX1268 datasheet v1.1, section 9.6
#define RADIOLIB_SX126X_REG_RX_GAIN_RETENTION_2                0x02A1 // SX1268 datasheet v1.1, section 9.6


// SX126X SPI command variables
//RADIOLIB_SX126X_CMD_SET_SLEEP                                                MSB   LSB   DESCRIPTION
#define RADIOLIB_SX126X_SLEEP_START_COLD                       0b00000000  //  2     2     sleep mode: cold start, configuration is lost (default)
#define RADIOLIB_SX126X_SLEEP_START_WARM                       0b00000100  //  2     2                 warm start, configuration is retained
#define RADIOLIB_SX126X_SLEEP_RTC_OFF                          0b00000000  //  0     0     wake on RTC timeout: disabled
#define RADIOLIB_SX126X_SLEEP_RTC_ON                           0b00000001  //  0     0                          enabled

//RADIOLIB_SX126X_CMD_SET_STANDBY
#define RADIOLIB_SX126X_STANDBY_RC                             0x00        //  7     0     standby mode: 13 MHz RC oscillator
#define RADIOLIB_SX126X_STANDBY_XOSC                           0x01        //  7     0                   32 MHz crystal oscillator

//RADIOLIB_SX126X_CMD_SET_RX
#define RADIOLIB_SX126X_RX_TIMEOUT_NONE                        0x000000    //  23    0     Rx timeout duration: no timeout (Rx single mode)
#define RADIOLIB_SX126X_RX_TIMEOUT_INF                         0xFFFFFF    //  23    0                          infinite (Rx continuous mode)

//RADIOLIB_SX126X_CMD_SET_TX
#define RADIOLIB_SX126X_TX_TIMEOUT_NONE                        0x000000    //  23    0     Tx timeout duration: no timeout (Tx single mode)

//RADIOLIB_SX126X_CMD_STOP_TIMER_ON_PREAMBLE
#define RADIOLIB_SX126X_STOP_ON_PREAMBLE_OFF                   0x00        //  7     0     stop timer on: sync word or header (default)
#define RADIOLIB_SX126X_STOP_ON_PREAMBLE_ON                    0x01        //  7     0                    preamble detection

//RADIOLIB_SX126X_CMD_SET_REGULATOR_MODE
#define RADIOLIB_SX126X_REGULATOR_LDO                          0x00        //  7     0     set regulator mode: LDO (default)
#define RADIOLIB_SX126X_REGULATOR_DC_DC                        0x01        //  7     0                         DC-DC

//RADIOLIB_SX126X_CMD_CALIBRATE
#define RADIOLIB_SX126X_CALIBRATE_IMAGE_OFF                    0b00000000  //  6     6     image calibration: disabled
#define RADIOLIB_SX126X_CALIBRATE_IMAGE_ON                     0b01000000  //  6     6                        enabled
#define RADIOLIB_SX126X_CALIBRATE_ADC_BULK_P_OFF               0b00000000  //  5     5     ADC bulk P calibration: disabled
#define RADIOLIB_SX126X_CALIBRATE_ADC_BULK_P_ON                0b00100000  //  5     5                             enabled
#define RADIOLIB_SX126X_CALIBRATE_ADC_BULK_N_OFF               0b00000000  //  4     4     ADC bulk N calibration: disabled
#define RADIOLIB_SX126X_CALIBRATE_ADC_BULK_N_ON                0b00010000  //  4     4                             enabled
#define RADIOLIB_SX126X_CALIBRATE_ADC_PULSE_OFF                0b00000000  //  3     3     ADC pulse calibration: disabled
#define RADIOLIB_SX126X_CALIBRATE_ADC_PULSE_ON                 0b00001000  //  3     3                            enabled
#define RADIOLIB_SX126X_CALIBRATE_PLL_OFF                      0b00000000  //  2     2     PLL calibration: disabled
#define RADIOLIB_SX126X_CALIBRATE_PLL_ON                       0b00000100  //  2     2                      enabled
#define RADIOLIB_SX126X_CALIBRATE_RC13M_OFF                    0b00000000  //  1     1     13 MHz RC osc. calibration: disabled
#define RADIOLIB_SX126X_CALIBRATE_RC13M_ON                     0b00000010  //  1     1                                 enabled
#define RADIOLIB_SX126X_CALIBRATE_RC64K_OFF                    0b00000000  //  0     0     64 kHz RC osc. calibration: disabled
#define RADIOLIB_SX126X_CALIBRATE_RC64K_ON                     0b00000001  //  0     0                                 enabled
#define RADIOLIB_SX126X_CALIBRATE_ALL                          0b01111111  //  6     0     calibrate all blocks

//RADIOLIB_SX126X_CMD_CALIBRATE_IMAGE
#define RADIOLIB_SX126X_CAL_IMG_430_MHZ_1                      0x6B
#define RADIOLIB_SX126X_CAL_IMG_430_MHZ_2                      0x6F
#define RADIOLIB_SX126X_CAL_IMG_470_MHZ_1                      0x75
#define RADIOLIB_SX126X_CAL_IMG_470_MHZ_2                      0x81
#define RADIOLIB_SX126X_CAL_IMG_779_MHZ_1                      0xC1
#define RADIOLIB_SX126X_CAL_IMG_779_MHZ_2                      0xC5
#define RADIOLIB_SX126X_CAL_IMG_863_MHZ_1                      0xD7
#define RADIOLIB_SX126X_CAL_IMG_863_MHZ_2                      0xDB
#define RADIOLIB_SX126X_CAL_IMG_902_MHZ_1                      0xE1
#define RADIOLIB_SX126X_CAL_IMG_902_MHZ_2                      0xE9

//RADIOLIB_SX126X_CMD_SET_PA_CONFIG
#define RADIOLIB_SX126X_PA_CONFIG_HP_MAX                       0x07
#define RADIOLIB_SX126X_PA_CONFIG_PA_LUT                       0x01
#define RADIOLIB_SX126X_PA_CONFIG_SX1262_8                     0x00

//RADIOLIB_SX126X_CMD_SET_RX_TX_FALLBACK_MODE
#define RADIOLIB_SX126X_RX_TX_FALLBACK_MODE_FS                 0x40        //  7     0     after Rx/Tx go to: FS mode
#define RADIOLIB_SX126X_RX_TX_FALLBACK_MODE_STDBY_XOSC         0x30        //  7     0                        standby with crystal oscillator
#define RADIOLIB_SX126X_RX_TX_FALLBACK_MODE_STDBY_RC           0x20        //  7     0                        standby with RC oscillator (default)

//RADIOLIB_SX126X_CMD_SET_DIO_IRQ_PARAMS
#define RADIOLIB_SX126X_IRQ_TIMEOUT                          0b1000000000  //  9     9     Rx or Tx timeout
#define RADIOLIB_SX126X_IRQ_CAD_DETECTED                     0b0100000000  //  8     8     channel activity detected
#define RADIOLIB_SX126X_IRQ_CAD_DONE                         0b0010000000  //  7     7     channel activity detection finished
#define RADIOLIB_SX126X_IRQ_CRC_ERR                          0b0001000000  //  6     6     wrong CRC received
#define RADIOLIB_SX126X_IRQ_HEADER_ERR                       0b0000100000  //  5     5     LoRa header CRC error
#define RADIOLIB_SX126X_IRQ_HEADER_VALID                     0b0000010000  //  4     4     valid LoRa header received
#define RADIOLIB_SX126X_IRQ_SYNC_WORD_VALID                  0b0000001000  //  3     3     valid sync word detected
#define RADIOLIB_SX126X_IRQ_RADIOLIB_PREAMBLE_DETECTED       0b0000000100  //  2     2     preamble detected
#define RADIOLIB_SX126X_IRQ_RX_DONE                          0b0000000010  //  1     1     packet received
#define RADIOLIB_SX126X_IRQ_TX_DONE                          0b0000000001  //  0     0     packet transmission completed
#define RADIOLIB_SX126X_IRQ_ALL                              0b1111111111  //  9     0     all interrupts
#define RADIOLIB_SX126X_IRQ_NONE                             0b0000000000  //  9     0     no interrupts

//RADIOLIB_SX126X_CMD_SET_DIO2_AS_RF_SWITCH_CTRL
#define RADIOLIB_SX126X_DIO2_AS_IRQ                            0x00        //  7     0     DIO2 configuration: IRQ
#define RADIOLIB_SX126X_DIO2_AS_RF_SWITCH                      0x01        //  7     0                         RF switch control

//RADIOLIB_SX126X_CMD_SET_DIO3_AS_TCXO_CTRL
#define RADIOLIB_SX126X_DIO3_OUTPUT_1_6                        0x00        //  7     0     DIO3 voltage output for TCXO: 1.6 V
#define RADIOLIB_SX126X_DIO3_OUTPUT_1_7                        0x01        //  7     0                                   1.7 V
#define RADIOLIB_SX126X_DIO3_OUTPUT_1_8                        0x02        //  7     0                                   1.8 V
#define RADIOLIB_SX126X_DIO3_OUTPUT_2_2                        0x03        //  7     0                                   2.2 V
#define RADIOLIB_SX126X_DIO3_OUTPUT_2_4                        0x04        //  7     0                                   2.4 V
#define RADIOLIB_SX126X_DIO3_OUTPUT_2_7                        0x05        //  7     0                                   2.7 V
#define RADIOLIB_SX126X_DIO3_OUTPUT_3_0                        0x06        //  7     0                                   3.0 V
#define RADIOLIB_SX126X_DIO3_OUTPUT_3_3                        0x07        //  7     0                                   3.3 V

//RADIOLIB_SX126X_CMD_SET_PACKET_TYPE
#define RADIOLIB_SX126X_PACKET_TYPE_GFSK                       0x00        //  7     0     packet type: GFSK
#define RADIOLIB_SX126X_PACKET_TYPE_LORA                       0x01        //  7     0                  LoRa

//RADIOLIB_SX126X_CMD_SET_TX_PARAMS
#define RADIOLIB_SX126X_PA_RAMP_10U                            0x00        //  7     0     ramp time: 10 us
#define RADIOLIB_SX126X_PA_RAMP_20U                            0x01        //  7     0                20 us
#define RADIOLIB_SX126X_PA_RAMP_40U                            0x02        //  7     0                40 us
#define RADIOLIB_SX126X_PA_RAMP_80U                            0x03        //  7     0                80 us
#define RADIOLIB_SX126X_PA_RAMP_200U                           0x04        //  7     0                200 us
#define RADIOLIB_SX126X_PA_RAMP_800U                           0x05        //  7     0                800 us
#define RADIOLIB_SX126X_PA_RAMP_1700U                          0x06        //  7     0                1700 us
#define RADIOLIB_SX126X_PA_RAMP_3400U                          0x07        //  7     0                3400 us

//RADIOLIB_SX126X_CMD_SET_MODULATION_PARAMS
#define SX126X_GFSK_FILTER_NONE                       0x00        //  7     0     GFSK filter: none
#define SX126X_GFSK_FILTER_GAUSS_0_3                  0x08        //  7     0                  Gaussian, BT = 0.3
#define SX126X_GFSK_FILTER_GAUSS_0_5                  0x09        //  7     0                  Gaussian, BT = 0.5
#define SX126X_GFSK_FILTER_GAUSS_0_7                  0x0A        //  7     0                  Gaussian, BT = 0.7
#define SX126X_GFSK_FILTER_GAUSS_1                    0x0B        //  7     0                  Gaussian, BT = 1
#define SX126X_GFSK_RX_BW_4_8                         0x1F        //  7     0     GFSK Rx bandwidth: 4.8 kHz
#define SX126X_GFSK_RX_BW_5_8                         0x17        //  7     0                        5.8 kHz
#define SX126X_GFSK_RX_BW_7_3                         0x0F        //  7     0                        7.3 kHz
#define SX126X_GFSK_RX_BW_9_7                         0x1E        //  7     0                        9.7 kHz
#define SX126X_GFSK_RX_BW_11_7                        0x16        //  7     0                        11.7 kHz
#define SX126X_GFSK_RX_BW_14_6                        0x0E        //  7     0                        14.6 kHz
#define SX126X_GFSK_RX_BW_19_5                        0x1D        //  7     0                        19.5 kHz
#define SX126X_GFSK_RX_BW_23_4                        0x15        //  7     0                        23.4 kHz
#define SX126X_GFSK_RX_BW_29_3                        0x0D        //  7     0                        29.3 kHz
#define SX126X_GFSK_RX_BW_39_0                        0x1C        //  7     0                        39.0 kHz
#define SX126X_GFSK_RX_BW_46_9                        0x14        //  7     0                        46.9 kHz
#define SX126X_GFSK_RX_BW_58_6                        0x0C        //  7     0                        58.6 kHz
#define SX126X_GFSK_RX_BW_78_2                        0x1B        //  7     0                        78.2 kHz
#define SX126X_GFSK_RX_BW_93_8                        0x13        //  7     0                        93.8 kHz
#define SX126X_GFSK_RX_BW_117_3                       0x0B        //  7     0                        117.3 kHz
#define SX126X_GFSK_RX_BW_156_2                       0x1A        //  7     0                        156.2 kHz
#define SX126X_GFSK_RX_BW_187_2                       0x12        //  7     0                        187.2 kHz
#define SX126X_GFSK_RX_BW_234_3                       0x0A        //  7     0                        234.3 kHz
#define SX126X_GFSK_RX_BW_312_0                       0x19        //  7     0                        312.0 kHz
#define SX126X_GFSK_RX_BW_373_6                       0x11        //  7     0                        373.6 kHz
#define SX126X_GFSK_RX_BW_467_0                       0x09        //  7     0                        467.0 kHz

#define SX126X_LORA_SF_5                              0x05        //  7     0     LoRa Spreading Factor: 5
#define SX126X_LORA_SF_6                              0x06        //  7     0                            6
#define SX126X_LORA_SF_7                              0x07        //  7     0                            7
#define SX126X_LORA_SF_8                              0x08        //  7     0                            8
#define SX126X_LORA_SF_9                              0x09        //  7     0                            9
#define SX126X_LORA_SF_10                             0x0A        //  7     0                            10
#define SX126X_LORA_SF_11                             0x0B        //  7     0                            11
#define SX126X_LORA_SF_12                             0x0C        //  7     0                            12

#define SX126X_LORA_BW_7_8                            0x00        //  7     0     LoRa bandwidth: 7.8 kHz
#define SX126X_LORA_BW_10_4                           0x08        //  7     0                     10.4 kHz
#define SX126X_LORA_BW_15_6                           0x01        //  7     0                     15.6 kHz
#define SX126X_LORA_BW_20_8                           0x09        //  7     0                     20.8 kHz
#define SX126X_LORA_BW_31_25                          0x02        //  7     0                     31.25 kHz
#define SX126X_LORA_BW_41_7                           0x0A        //  7     0                     41.7 kHz
#define SX126X_LORA_BW_62_5                           0x03        //  7     0                     62.5 kHz
#define SX126X_LORA_BW_125_0                          0x04        //  7     0                     125.0 kHz
#define SX126X_LORA_BW_250_0                          0x05        //  7     0                     250.0 kHz
#define SX126X_LORA_BW_500_0                          0x06        //  7     0                     500.0 kHz
#define SX126X_LORA_CR_4_5                            0x01        //  7     0     LoRa coding rate: 4/5
#define SX126X_LORA_CR_4_6                            0x02        //  7     0                       4/6
#define SX126X_LORA_CR_4_7                            0x03        //  7     0                       4/7
#define SX126X_LORA_CR_4_8                            0x04        //  7     0                       4/8
#define SX126X_LORA_LOW_DATA_RATE_OPTIMIZE_OFF        0x00        //  7     0     LoRa low data rate optimization: disabled
#define SX126X_LORA_LOW_DATA_RATE_OPTIMIZE_ON         0x01        //  7     0                                      enabled

//RADIOLIB_SX126X_CMD_SET_PACKET_PARAMS
#define RADIOLIB_SX126X_GFSK_PREAMBLE_DETECT_OFF               0x00        //  7     0     GFSK minimum preamble length before reception starts: detector disabled
#define RADIOLIB_SX126X_GFSK_PREAMBLE_DETECT_8                 0x04        //  7     0                                                           8 bits
#define RADIOLIB_SX126X_GFSK_PREAMBLE_DETECT_16                0x05        //  7     0                                                           16 bits
#define RADIOLIB_SX126X_GFSK_PREAMBLE_DETECT_24                0x06        //  7     0                                                           24 bits
#define RADIOLIB_SX126X_GFSK_PREAMBLE_DETECT_32                0x07        //  7     0                                                           32 bits
#define RADIOLIB_SX126X_GFSK_ADDRESS_FILT_OFF                  0x00        //  7     0     GFSK address filtering: disabled
#define RADIOLIB_SX126X_GFSK_ADDRESS_FILT_NODE                 0x01        //  7     0                             node only
#define RADIOLIB_SX126X_GFSK_ADDRESS_FILT_NODE_BROADCAST       0x02        //  7     0                             node and broadcast
#define RADIOLIB_SX126X_GFSK_PACKET_FIXED                      0x00        //  7     0     GFSK packet type: fixed (payload length known in advance to both sides)
#define RADIOLIB_SX126X_GFSK_PACKET_VARIABLE                   0x01        //  7     0                       variable (payload length added to packet)
#define RADIOLIB_SX126X_GFSK_CRC_OFF                           0x01        //  7     0     GFSK packet CRC: disabled
#define RADIOLIB_SX126X_GFSK_CRC_1_BYTE                        0x00        //  7     0                      1 byte
#define RADIOLIB_SX126X_GFSK_CRC_2_BYTE                        0x02        //  7     0                      2 byte
#define RADIOLIB_SX126X_GFSK_CRC_1_BYTE_INV                    0x04        //  7     0                      1 byte, inverted
#define RADIOLIB_SX126X_GFSK_CRC_2_BYTE_INV                    0x06        //  7     0                      2 byte, inverted
#define RADIOLIB_SX126X_GFSK_WHITENING_OFF                     0x00        //  7     0     GFSK data whitening: disabled
#define RADIOLIB_SX126X_GFSK_WHITENING_ON                      0x01        //  7     0                          enabled
#define RADIOLIB_SX126X_LORA_HEADER_EXPLICIT                   0x00        //  7     0     LoRa header mode: explicit
#define RADIOLIB_SX126X_LORA_HEADER_IMPLICIT                   0x01        //  7     0                       implicit
#define RADIOLIB_SX126X_LORA_CRC_OFF                           0x00        //  7     0     LoRa CRC mode: disabled
#define RADIOLIB_SX126X_LORA_CRC_ON                            0x01        //  7     0                    enabled
#define RADIOLIB_SX126X_LORA_IQ_STANDARD                       0x00        //  7     0     LoRa IQ setup: standard
#define RADIOLIB_SX126X_LORA_IQ_INVERTED                       0x01        //  7     0                    inverted

//RADIOLIB_SX126X_CMD_SET_CAD_PARAMS
#define RADIOLIB_SX126X_CAD_ON_1_SYMB                          0x00        //  7     0     number of symbols used for CAD: 1
#define RADIOLIB_SX126X_CAD_ON_2_SYMB                          0x01        //  7     0                                     2
#define RADIOLIB_SX126X_CAD_ON_4_SYMB                          0x02        //  7     0                                     4
#define RADIOLIB_SX126X_CAD_ON_8_SYMB                          0x03        //  7     0                                     8
#define RADIOLIB_SX126X_CAD_ON_16_SYMB                         0x04        //  7     0                                     16
#define RADIOLIB_SX126X_CAD_GOTO_STDBY                         0x00        //  7     0     after CAD is done, always go to STDBY_RC mode
#define RADIOLIB_SX126X_CAD_GOTO_RX                            0x01        //  7     0     after CAD is done, go to Rx mode if activity is detected

//RADIOLIB_SX126X_CMD_GET_STATUS
#define RADIOLIB_SX126X_STATUS_MODE_STDBY_RC                   0b00100000  //  6     4     current chip mode: STDBY_RC
#define RADIOLIB_SX126X_STATUS_MODE_STDBY_XOSC                 0b00110000  //  6     4                        STDBY_XOSC
#define RADIOLIB_SX126X_STATUS_MODE_FS                         0b01000000  //  6     4                        FS
#define RADIOLIB_SX126X_STATUS_MODE_RX                         0b01010000  //  6     4                        RX
#define RADIOLIB_SX126X_STATUS_MODE_TX                         0b01100000  //  6     4                        TX
#define RADIOLIB_SX126X_STATUS_DATA_AVAILABLE                  0b00000100  //  3     1     command status: packet received and data can be retrieved
#define RADIOLIB_SX126X_STATUS_CMD_TIMEOUT                     0b00000110  //  3     1                     SPI command timed out
#define RADIOLIB_SX126X_STATUS_CMD_INVALID                     0b00001000  //  3     1                     invalid SPI command
#define RADIOLIB_SX126X_STATUS_CMD_FAILED                      0b00001010  //  3     1                     SPI command failed to execute
#define RADIOLIB_SX126X_STATUS_TX_DONE                         0b00001100  //  3     1                     packet transmission done
#define RADIOLIB_SX126X_STATUS_SPI_FAILED                      0b11111111  //  7     0     SPI transaction failed

//RADIOLIB_SX126X_CMD_GET_PACKET_STATUS
#define RADIOLIB_SX126X_GFSK_RX_STATUS_PREAMBLE_ERR            0b10000000  //  7     7     GFSK Rx status: preamble error
#define RADIOLIB_SX126X_GFSK_RX_STATUS_SYNC_ERR                0b01000000  //  6     6                     sync word error
#define RADIOLIB_SX126X_GFSK_RX_STATUS_ADRS_ERR                0b00100000  //  5     5                     address error
#define RADIOLIB_SX126X_GFSK_RX_STATUS_CRC_ERR                 0b00010000  //  4     4                     CRC error
#define RADIOLIB_SX126X_GFSK_RX_STATUS_LENGTH_ERR              0b00001000  //  3     3                     length error
#define RADIOLIB_SX126X_GFSK_RX_STATUS_ABORT_ERR               0b00000100  //  2     2                     abort error
#define RADIOLIB_SX126X_GFSK_RX_STATUS_PACKET_RECEIVED         0b00000010  //  2     2                     packet received
#define RADIOLIB_SX126X_GFSK_RX_STATUS_PACKET_SENT             0b00000001  //  2     2                     packet sent

//RADIOLIB_SX126X_CMD_GET_DEVICE_ERRORS
#define RADIOLIB_SX126X_PA_RAMP_ERR                           0b100000000  //  8     8     device errors: PA ramping failed
#define RADIOLIB_SX126X_PLL_LOCK_ERR                          0b001000000  //  6     6                    PLL failed to lock
#define RADIOLIB_SX126X_XOSC_START_ERR                        0b000100000  //  5     5                    crystal oscillator failed to start
#define RADIOLIB_SX126X_IMG_CALIB_ERR                         0b000010000  //  4     4                    image calibration failed
#define RADIOLIB_SX126X_ADC_CALIB_ERR                         0b000001000  //  3     3                    ADC calibration failed
#define RADIOLIB_SX126X_PLL_CALIB_ERR                         0b000000100  //  2     2                    PLL calibration failed
#define RADIOLIB_SX126X_RC13M_CALIB_ERR                       0b000000010  //  1     1                    RC13M calibration failed
#define RADIOLIB_SX126X_RC64K_CALIB_ERR                       0b000000001  //  0     0                    RC64K calibration failed


// SX126X SPI register variables
//RADIOLIB_SX126X_REG_LORA_SYNC_WORD_MSB + LSB
#define RADIOLIB_SX126X_SYNC_WORD_PUBLIC                       0x34        // actually 0x3444  NOTE: The low nibbles in each byte (0x_4_4) are masked out since apparently, they're reserved.
#define RADIOLIB_SX126X_SYNC_WORD_PRIVATE                      0x12        // actually 0x1424        You couldn't make this up if you tried.


/* ---------------------------------------------- */

//#define SX126X_LORA_LOW_DATA_RATE_OPTIMIZE_OFF        0x00        //  7     0     LoRa low data rate optimization: disabled
//#define SX126X_LORA_LOW_DATA_RATE_OPTIMIZE_ON         0x01        //  7     0                                      enabled

typedef enum
{
    SX126x_BW_7_80_KHZ = SX126X_LORA_BW_7_8,
    SX126x_BW_10_40_KHZ = SX126X_LORA_BW_10_4,
    SX126x_BW_15_60_KHZ = SX126X_LORA_BW_15_6,
    SX126x_BW_20_80_KHZ = SX126X_LORA_BW_20_8,
    SX126x_BW_31_25_KHZ = SX126X_LORA_BW_31_25,
    SX126x_BW_41_70_KHZ = SX126X_LORA_BW_41_7,
    SX126x_BW_62_50_KHZ = SX126X_LORA_BW_62_5,
    SX126x_BW_125_00_KHZ = SX126X_LORA_BW_125_0,
    SX126x_BW_250_00_KHZ = SX126X_LORA_BW_250_0,
    SX126x_BW_500_00_KHZ = SX126X_LORA_BW_500_0,
} SX126x_Bandwidth;

typedef enum
{
    SX126x_SF_5 = SX126X_LORA_SF_5,
    SX126x_SF_6 = SX126X_LORA_SF_6,
    SX126x_SF_7 = SX126X_LORA_SF_7,
    SX126x_SF_8 = SX126X_LORA_SF_8,
    SX126x_SF_9 = SX126X_LORA_SF_9,
    SX126x_SF_10 = SX126X_LORA_SF_10,
    SX126x_SF_11 = SX126X_LORA_SF_11,
    SX126x_SF_12 = SX126X_LORA_SF_12,
} SX126x_SpreadingFactor;

typedef enum
{
    SX126x_CR_4_5 = SX126X_LORA_CR_4_5,
    SX126x_CR_4_6 = SX126X_LORA_CR_4_6,
    SX126x_CR_4_7 = SX126X_LORA_CR_4_7,
    SX126x_CR_4_8 = SX126X_LORA_CR_4_7,
} SX126x_CodingRate;

#if 0

typedef enum
{
    SX126x_OPMODE_FSK_OOK = 0b00000000,
    SX126x_OPMODE_LORA = 0b10000000,
    SX126x_ACCESS_SHARED_REG_OFF = 0b00000000,
    SX126x_ACCESS_SHARED_REG_ON = 0b01000000
} SX126x_ModulationModes;

typedef enum
{
    SX126x_OPMODE_SLEEP = 0b00000000,
    SX126x_OPMODE_STANDBY = 0b00000001,
    SX126x_OPMODE_FSTX = 0b00000010,
    SX126x_OPMODE_TX = 0b00000011,
    SX126x_OPMODE_FSRX = 0b00000100,
    SX126x_OPMODE_RXCONTINUOUS = 0b00000101,
    SX126x_OPMODE_RXSINGLE = 0b00000110,
    SX126x_OPMODE_CAD = 0b00000111,
} SX126x_RadioOPmodes;

// SX126x series common registers
#define SX126X_REG_FIFO 0x00
#define SX126X_REG_OP_MODE 0x01
#define SX126X_REG_FRF_MSB 0x06
#define SX126X_REG_FRF_MID 0x07
#define SX126X_REG_FRF_LSB 0x08
#define SX126X_REG_PA_CONFIG 0x09
#define SX126X_REG_PA_RAMP 0x0A
#define SX126X_REG_OCP 0x0B
#define SX126X_REG_LNA 0x0C
#define SX126X_REG_FIFO_ADDR_PTR 0x0D
#define SX126X_REG_FIFO_TX_BASE_ADDR 0x0E
#define SX126X_REG_FIFO_RX_BASE_ADDR 0x0F
#define SX126X_REG_FIFO_RX_CURRENT_ADDR 0x10
#define SX126X_REG_IRQ_FLAGS_MASK 0x11
#define SX126X_REG_IRQ_FLAGS 0x12
#define SX126X_REG_RX_NB_BYTES 0x13
#define SX126X_REG_RX_HEADER_CNT_VALUE_MSB 0x14
#define SX126X_REG_RX_HEADER_CNT_VALUE_LSB 0x15
#define SX126X_REG_RX_PACKET_CNT_VALUE_MSB 0x16
#define SX126X_REG_RX_PACKET_CNT_VALUE_LSB 0x17
#define SX126X_REG_MODEM_STAT 0x18
#define SX126X_REG_PKT_SNR_VALUE 0x19
#define SX126X_REG_PKT_RSSI_VALUE 0x1A
#define SX126X_REG_RSSI_VALUE 0x1B
#define SX126X_REG_HOP_CHANNEL 0x1C
#define SX126X_REG_MODEM_CONFIG_1 0x1D
#define SX126X_REG_MODEM_CONFIG_2 0x1E
#define SX126X_REG_SYMB_TIMEOUT_LSB 0x1F
#define SX126X_REG_PREAMBLE_MSB 0x20
#define SX126X_REG_PREAMBLE_LSB 0x21
#define SX126X_REG_PAYLOAD_LENGTH 0x22
#define SX126X_REG_MAX_PAYLOAD_LENGTH 0x23
#define SX126X_REG_HOP_PERIOD 0x24
#define SX126X_REG_FIFO_RX_BYTE_ADDR 0x25
#define SX126X_REG_FEI_MSB 0x28
#define SX126X_REG_FEI_MID 0x29
#define SX126X_REG_FEI_LSB 0x2A
#define SX126X_REG_RSSI_WIDEBAND 0x2C
#define SX126X_REG_DETECT_OPTIMIZE 0x31
#define SX126X_REG_INVERT_IQ 0x33
#define SX126X_REG_DETECTION_THRESHOLD 0x37
#define SX126X_REG_SYNC_WORD 0x39
#define SX126X_REG_DIO_MAPPING_1 0x40
#define SX126X_REG_DIO_MAPPING_2 0x41
#define SX126X_REG_VERSION 0x42

// SX127X_REG_PA_CONFIG
#define SX127X_PA_SELECT_RFO 0b00000000    //  7     7     RFO pin output, power limited to +14 dBm
#define SX127X_PA_SELECT_BOOST 0b10000000  //  7     7     PA_BOOST pin output, power limited to +20 dBm
#define SX127X_OUTPUT_POWER 0b00001111     //  3     0     output power: P_out = 17 - (15 - OUTPUT_POWER) [dBm] for PA_SELECT_BOOST
#ifdef TARGET_TX_BETAFPV_900_V1
    #define SX127X_MAX_OUTPUT_POWER 0b00000000 //              Enable max output power
#else
    #define SX127X_MAX_OUTPUT_POWER 0b01110000 //              Enable max output power
#endif
// SX127X_REG_OCP
#define SX127X_OCP_OFF 0b00000000   //  5     5     PA overload current protection disabled
#define SX127X_OCP_ON 0b00100000    //  5     5     PA overload current protection enabled
#define SX127X_OCP_TRIM 0b00001011  //  4     0     OCP current: I_max(OCP_TRIM = 0b1011) = 100 mA
#define SX127X_OCP_150MA 0b00010010 //  4     0     OCP current: I_max(OCP_TRIM = 10010) = 150 mA

// SX127X_REG_LNA
#define SX127X_LNA_GAIN_0 0b00000000    //  7     5     LNA gain setting:   not used
#define SX127X_LNA_GAIN_1 0b00100000    //  7     5                         max gain
#define SX127X_LNA_GAIN_2 0b01000000    //  7     5                         .
#define SX127X_LNA_GAIN_3 0b01100000    //  7     5                         .
#define SX127X_LNA_GAIN_4 0b10000000    //  7     5                         .
#define SX127X_LNA_GAIN_5 0b10100000    //  7     5                         .
#define SX127X_LNA_GAIN_6 0b11000000    //  7     5                         min gain
#define SX127X_LNA_GAIN_7 0b11100000    //  7     5                         not used
#define SX127X_LNA_BOOST_OFF 0b00000000 //  1     0     default LNA current
#define SX127X_LNA_BOOST_ON 0b00000011  //  1     0     150% LNA current

#define SX127X_TX_MODE_SINGLE 0b00000000 //  3     3     single TX
#define SX127X_TX_MODE_CONT 0b00001000   //  3     3     continuous TX
#define SX127X_RX_TIMEOUT_MSB 0b00000000 //  1     0

// SX127X_REG_SYMB_TIMEOUT_LSB
#define SX127X_RX_TIMEOUT_LSB 0b01100100 //  7     0     10 bit RX operation timeout

// SX127X_REG_PREAMBLE_MSB + REG_PREAMBLE_LSB
#define SX127X_PREAMBLE_LENGTH_MSB 0b00000000 //  7     0     2 byte preamble length setting: l_P = PREAMBLE_LENGTH + 4.25
#define SX127X_PREAMBLE_LENGTH_LSB 0b00001000 //  7     0         where l_p = preamble length
//#define SX127X_PREAMBLE_LENGTH_LSB                    0b00000100  //  7     0         where l_p = preamble length  //CHANGED

// SX127X_REG_DETECT_OPTIMIZE
#define SX127X_DETECT_OPTIMIZE_SF_6 0b00000101    //  2     0     SF6 detection optimization
#define SX127X_DETECT_OPTIMIZE_SF_7_12 0b00000011 //  2     0     SF7 to SF12 detection optimization

// SX127X_REG_DETECTION_THRESHOLD
#define SX127X_DETECTION_THRESHOLD_SF_6 0b00001100    //  7     0     SF6 detection threshold
#define SX127X_DETECTION_THRESHOLD_SF_7_12 0b00001010 //  7     0     SF7 to SF12 detection threshold

// SX127X_REG_PA_DAC
#define SX127X_PA_BOOST_OFF 0b00000100 //  2     0     PA_BOOST disabled
#define SX127X_PA_BOOST_ON 0b00000111  //  2     0     +20 dBm on PA_BOOST when OUTPUT_POWER = 0b1111

// SX127X_REG_HOP_PERIOD
#define SX127X_HOP_PERIOD_OFF 0b00000000 //  7     0     number of periods between frequency hops; 0 = disabled
#define SX127X_HOP_PERIOD_MAX 0b11111111 //  7     0

// SX127X_REG_DIO_MAPPING_1
#define SX127X_DIO0_RX_DONE 0b00000000             //  7     6
#define SX127X_DIO0_TX_DONE 0b01000000             //  7     6
#define SX127X_DIO0_CAD_DONE 0b10000000            //  7     6
#define SX127X_DIO1_RX_TIMEOUT 0b00000000          //  5     4
#define SX127X_DIO1_FHSS_CHANGE_CHANNEL 0b00010000 //  5     4
#define SX127X_DIO1_CAD_DETECTED 0b00100000        //  5     4

// SX127X_REG_IRQ_FLAGS
#define SX127X_CLEAR_IRQ_FLAG_RX_TIMEOUT 0b10000000          //  7     7     timeout
#define SX127X_CLEAR_IRQ_FLAG_RX_DONE 0b01000000             //  6     6     packet reception complete
#define SX127X_CLEAR_IRQ_FLAG_PAYLOAD_CRC_ERROR 0b00100000   //  5     5     payload CRC error
#define SX127X_CLEAR_IRQ_FLAG_VALID_HEADER 0b00010000        //  4     4     valid header received
#define SX127X_CLEAR_IRQ_FLAG_TX_DONE 0b00001000             //  3     3     payload transmission complete
#define SX127X_CLEAR_IRQ_FLAG_CAD_DONE 0b00000100            //  2     2     CAD complete
#define SX127X_CLEAR_IRQ_FLAG_FHSS_CHANGE_CHANNEL 0b00000010 //  1     1     FHSS change channel
#define SX127X_CLEAR_IRQ_FLAG_CAD_DETECTED 0b00000001        //  0     0     valid LoRa signal detected during CAD operation

// SX127X_REG_IRQ_FLAGS_MASK
#define SX127X_MASK_IRQ_FLAG_RX_TIMEOUT 0b01111111          //  7     7     timeout
#define SX127X_MASK_IRQ_FLAG_RX_DONE 0b10111111             //  6     6     packet reception complete
#define SX127X_MASK_IRQ_FLAG_PAYLOAD_CRC_ERROR 0b11011111   //  5     5     payload CRC error
#define SX127X_MASK_IRQ_FLAG_VALID_HEADER 0b11101111        //  4     4     valid header received
#define SX127X_MASK_IRQ_FLAG_TX_DONE 0b11110111             //  3     3     payload transmission complete
#define SX127X_MASK_IRQ_FLAG_CAD_DONE 0b11111011            //  2     2     CAD complete
#define SX127X_MASK_IRQ_FLAG_FHSS_CHANGE_CHANNEL 0b11111101 //  1     1     FHSS change channel
#define SX127X_MASK_IRQ_FLAG_CAD_DETECTED 0b11111110        //  0     0     valid LoRa signal detected during CAD operation

// SX127X_REG_FIFO_TX_BASE_ADDR
#define SX127X_FIFO_TX_BASE_ADDR_MAX 0b00000000 //  7     0     allocate the entire FIFO buffer for TX only

// SX127X_REG_FIFO_RX_BASE_ADDR
#define SX127X_FIFO_RX_BASE_ADDR_MAX 0b00000000 //  7     0     allocate the entire FIFO buffer for RX only

// SX127X_REG_SYNC_WORD
//#define SX127X_SYNC_WORD 0xC8 //  200   0     default ExpressLRS sync word - 200Hz
#define SX127X_SYNC_WORD                              0x12        //  18    0     default LoRa sync word
#define SX127X_SYNC_WORD_LORAWAN 0x34 //  52    0     sync word reserved for LoRaWAN networks

#define IRQpin 26

///Added by Sandro
#define SX126x_TXCONTINUOUSMODE_MASK 0xF7
#define SX126x_TXCONTINUOUSMODE_ON 0x08
#define SX126x_TXCONTINUOUSMODE_OFF 0x00
#define SX126x_PPMOFFSET 0x27

///// SX1278 Regs /////
//SX1278 specific register map
#define SX1278_REG_MODEM_CONFIG_3 0x26
#define SX1278_REG_TCXO 0x4B
#define SX1278_REG_PA_DAC 0x4D
#define SX1278_REG_FORMER_TEMP 0x5D
#define SX1278_REG_AGC_REF 0x61
#define SX1278_REG_AGC_THRESH_1 0x62
#define SX1278_REG_AGC_THRESH_2 0x63
#define SX1278_REG_AGC_THRESH_3 0x64
#define SX1278_REG_PLL 0x70

//SX1278 LoRa modem settings
//SX1278_REG_OP_MODE                                                  MSB   LSB   DESCRIPTION
#define SX1278_HIGH_FREQ 0b00000000 //  3     3     access HF test registers
#define SX1278_LOW_FREQ 0b00001000  //  3     3     access LF test registers

//SX1278_REG_FRF_MSB + REG_FRF_MID + REG_FRF_LSB
#define SX1278_FRF_MSB 0x6C //  7     0     carrier frequency setting: f_RF = (F(XOSC) * FRF)/2^19
#define SX1278_FRF_MID 0x80 //  7     0         where F(XOSC) = 32 MHz
#define SX1278_FRF_LSB 0x00 //  7     0               FRF = 3 byte value of FRF registers

//SX1278_REG_PA_CONFIG
#define SX1278_MAX_POWER 0b01110000 //  6     4     max power: P_max = 10.8 + 0.6*MAX_POWER [dBm]; P_max(MAX_POWER = 0b111) = 15 dBm
//#define SX1278_MAX_POWER                              0b00010000  //  6     4     changed

//SX1278_REG_LNA
#define SX1278_LNA_BOOST_LF_OFF 0b00000000 //  4     3     default LNA current

#define SX1278_HEADER_EXPL_MODE 0b00000000 //  0     0     explicit header mode
#define SX1278_HEADER_IMPL_MODE 0b00000001 //  0     0     implicit header mode

//SX1278_REG_MODEM_CONFIG_2
#define SX1278_RX_CRC_MODE_OFF 0b00000000 //  2     2     CRC disabled
#define SX1278_RX_CRC_MODE_ON 0b00000100  //  2     2     CRC enabled

//SX1278_REG_MODEM_CONFIG_3
#define SX1278_LOW_DATA_RATE_OPT_OFF 0b00000000 //  3     3     low data rate optimization disabled
#define SX1278_LOW_DATA_RATE_OPT_ON 0b00001000  //  3     3     low data rate optimization enabled
#define SX1278_AGC_AUTO_OFF 0b00000000          //  2     2     LNA gain set by REG_LNA
#define SX1278_AGC_AUTO_ON 0b00000100           //  2     2     LNA gain set by internal AGC loop

#define SX1276_HEADER_EXPL_MODE 0b00000000 //  0     0     explicit header mode
#define SX1276_HEADER_IMPL_MODE 0b00000001 //  0     0     implicit header mode

#define ERR_NONE 0x00
#define ERR_CHIP_NOT_FOUND 0x01
#define ERR_EEPROM_NOT_INITIALIZED 0x02

#define ERR_PACKET_TOO_LONG 0x10
#define ERR_TX_TIMEOUT 0x11

#define ERR_RX_TIMEOUT 0x20
#define ERR_CRC_MISMATCH 0x21

#define ERR_INVALID_BANDWIDTH 0x30
#define ERR_INVALID_SPREADING_FACTOR 0x31
#define ERR_INVALID_CODING_RATE 0x32
#define ERR_INVALID_FREQUENCY 0x33

#define ERR_INVALID_BIT_RANGE 0x40

#define CHANNEL_FREE 0x50
#define PREAMBLE_DETECTED 0x51

#define SPI_READ 0b00000000
#define SPI_WRITE 0b10000000

#endif


