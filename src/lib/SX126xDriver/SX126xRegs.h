#pragma once

/* ---------------------------------------------------------- */

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


/* ---------------------------------------------------------- */

#define REG_LR_FIRMWARE_VERSION_MSB 0x0153 //The address of the register holding the firmware version MSB
#define SX126x_REG_LR_ESTIMATED_FREQUENCY_ERROR_MSB 0x0954
#define SX126x_REG_LR_ESTIMATED_FREQUENCY_ERROR_MASK 0x0FFFFF

#define SX126x_REG_SF_ADDITIONAL_CONFIG             0x925
#define SX126x_REG_FREQ_ERR_CORRECTION              0x93C

#define SX126x_XTAL_FREQ 32000000
#define FREQ_STEP ((double)(SX126x_XTAL_FREQ / pow(2.0, 18.0)))  // 198.3642578125

typedef enum
{
    SX126x_Radio_1 = 1 << 0,
    SX126x_Radio_2 = 1 << 1,
    SX126x_Radio_All = 0xFF,
} SX126x_Radio_Number_t;

typedef enum
{
    SX126x_RF_IDLE = 0x00, //!< The radio is idle
    SX126x_RF_RX_RUNNING,  //!< The radio is in reception state
    SX126x_RF_TX_RUNNING,  //!< The radio is in transmission state
    SX126x_RF_CAD,         //!< The radio is doing channel activity detection
} SX126x_RadioStates_t;

/*!
 * \brief Represents the operating mode the radio is actually running
 */
typedef enum
{
    SX126x_MODE_SLEEP = 0x00, //! The radio is in sleep mode
    SX126x_MODE_CALIBRATION,  //! The radio is in calibration mode
    SX126x_MODE_STDBY_RC,     //! The radio is in standby mode with RC oscillator
    SX126x_MODE_STDBY_XOSC,   //! The radio is in standby mode with XOSC oscillator
    SX126x_MODE_FS,           //! The radio is in frequency synthesis mode
    SX126x_MODE_RX,           //! The radio is in receive mode
    SX126x_MODE_TX,           //! The radio is in transmit mode
    SX126x_MODE_CAD           //! The radio is in channel activity detection mode
} SX126x_RadioOperatingModes_t;

#define SX126x_RX_TX_CONTINUOUS \
    (TickTime_t) { RADIO_TICK_SIZE_0015_US, 0xFFFF }
#define SX126x_RX_TX_SINGLE \
    (TickTime_t) { RADIO_TICK_SIZE_0015_US, 0 }

/*!
 * \brief Declares the oscillator in use while in standby mode
 *
 * Using the STDBY_RC standby mode allow to reduce the energy consumption
 * STDBY_XOSC should be used for time critical applications
 */
// TODO
typedef enum
{
    SX126x_STDBY_RC = 0x00,
    SX126x_STDBY_XOSC = 0x01,
} SX126x_RadioStandbyModes_t;

/*!
 * \brief Declares the power regulation used to power the device
 *
 * This command allows the user to specify if DC-DC or LDO is used for power regulation.
 * Using only LDO implies that the Rx or Tx current is doubled
 */
// TODO
typedef enum
{
    SX126x_USE_LDO = 0x00,  //! Use LDO (default value)
    SX126x_USE_DCDC = 0x01, //! Use DCDC
} SX126x_RadioRegulatorModes_t;

/*!
 * \brief Represents the possible packet type (i.e. modem) used
 */
// TODO
typedef enum
{
    SX126x_PACKET_TYPE_GFSK = 0x00,
    SX126x_PACKET_TYPE_LORA,
    SX126x_PACKET_TYPE_LR_FHSS = 0x03,
    SX126x_PACKET_TYPE_NONE = 0x0F,
} SX126x_RadioPacketTypes_t;

// TODO
typedef enum
{
    SX126x_LORA_IQ_NORMAL = 0x40,
    SX126x_LORA_IQ_INVERTED = 0x00,
} SX126x_RadioLoRaIQModes_t;

// TODO
typedef enum
{
    SX126x_RADIO_CRC_OFF = 0x00, //!< No CRC in use
    SX126x_RADIO_CRC_1_BYTES = 0x10,
    SX126x_RADIO_CRC_2_BYTES = 0x20,
    SX126x_RADIO_CRC_3_BYTES = 0x30,
} SX126x_RadioCrcTypes_t;

/*!
 * \brief Represents the ramping time for power amplifier
 */
// TODO
typedef enum
{
    SX126x_RADIO_RAMP_02_US = 0x00,
    SX126x_RADIO_RAMP_04_US = 0x20,
    SX126x_RADIO_RAMP_06_US = 0x40,
    SX126x_RADIO_RAMP_08_US = 0x60,
    SX126x_RADIO_RAMP_10_US = 0x80,
    SX126x_RADIO_RAMP_12_US = 0xA0,
    SX126x_RADIO_RAMP_16_US = 0xC0,
    SX126x_RADIO_RAMP_20_US = 0xE0,
} SX126x_RadioRampTimes_t;

/*!
 * \brief Represents the number of symbols to be used for channel activity detection operation
 */
// TODO
typedef enum
{
    SX126x_LORA_CAD_01_SYMBOL = 0x00,
    SX126x_LORA_CAD_02_SYMBOLS = 0x20,
    SX126x_LORA_CAD_04_SYMBOLS = 0x40,
    SX126x_LORA_CAD_08_SYMBOLS = 0x60,
    SX126x_LORA_CAD_16_SYMBOLS = 0x80,
} SX126x_RadioLoRaCadSymbols_t;

/*!
 * \brief Represents the possible spreading factor values in LORA packet types
 */
// TODO
typedef enum
{
    SX126x_LORA_SF5 = 0x50,
    SX126x_LORA_SF6 = 0x60,
    SX126x_LORA_SF7 = 0x70,
    SX126x_LORA_SF8 = 0x80,
    SX126x_LORA_SF9 = 0x90,
    SX126x_LORA_SF10 = 0xA0,
    SX126x_LORA_SF11 = 0xB0,
    SX126x_LORA_SF12 = 0xC0,
} SX126x_RadioLoRaSpreadingFactors_t;

/*!
 * \brief Represents the bandwidth values for LORA packet type
 */
// TODO
typedef enum
{
    SX126x_LORA_BW_0200 = 0x34,
    SX126x_LORA_BW_0400 = 0x26,
    SX126x_LORA_BW_0800 = 0x18,
    SX126x_LORA_BW_1600 = 0x0A,
} SX126x_RadioLoRaBandwidths_t;

/*!
 * \brief Represents the coding rate values for LORA packet type
 */
// TODO
typedef enum
{
    SX126x_LORA_CR_4_5 = 0x01,
    SX126x_LORA_CR_4_6 = 0x02,
    SX126x_LORA_CR_4_7 = 0x03,
    SX126x_LORA_CR_4_8 = 0x04,
    SX126x_LORA_CR_LI_4_5 = 0x05,
    SX126x_LORA_CR_LI_4_6 = 0x06,
    SX126x_LORA_CR_LI_4_7 = 0x07,
} SX126x_RadioLoRaCodingRates_t;

// TODO
typedef enum
{
    SX126x_LORA_PACKET_VARIABLE_LENGTH = 0x00, //!< The packet is on variable size, header included
    SX126x_LORA_PACKET_FIXED_LENGTH = 0x80,    //!< The packet is known on both sides, no header included in the packet
    SX126x_LORA_PACKET_EXPLICIT = SX126x_LORA_PACKET_VARIABLE_LENGTH,
    SX126x_LORA_PACKET_IMPLICIT = SX126x_LORA_PACKET_FIXED_LENGTH,
} SX126x_RadioLoRaPacketLengthsModes_t;

// TODO
typedef enum
{
    SX126x_LORA_CRC_ON = 0x20,  //!< CRC activated
    SX126x_LORA_CRC_OFF = 0x00, //!< CRC not used
} SX126x_RadioLoRaCrcModes_t;

// TODO
typedef enum RadioCommands_u
{
    SX126x_RADIO_GET_STATUS = 0xC0,
    SX126x_RADIO_WRITE_REGISTER = 0x0D,
    SX126x_RADIO_READ_REGISTER = 0x1D,
    SX126x_RADIO_WRITE_BUFFER = 0x0E,
    SX126x_RADIO_READ_BUFFER = 0x1E,
    SX126x_RADIO_SET_SLEEP = 0x84,
    SX126x_RADIO_SET_STANDBY = 0x80,
    SX126x_RADIO_SET_FS = 0xC1,
    SX126x_RADIO_SET_TX = 0x83,
    SX126x_RADIO_SET_RX = 0x82,
    SX126x_RADIO_SET_RXDUTYCYCLE = 0x94,
    SX126x_RADIO_SET_CAD = 0xC5,
    SX126x_RADIO_SET_TXCONTINUOUSWAVE = 0xD1,
    SX126x_RADIO_SET_TXCONTINUOUSPREAMBLE = 0xD2,
    SX126x_RADIO_SET_PACKETTYPE = 0x8A,
    SX126x_RADIO_GET_PACKETTYPE = 0x11,
    SX126x_RADIO_SET_RFFREQUENCY = 0x86,
    SX126x_RADIO_SET_TXPARAMS = 0x8E,
    SX126x_RADIO_SET_CADPARAMS = 0x88,
    SX126x_RADIO_SET_BUFFERBASEADDRESS = 0x8F,
    SX126x_RADIO_SET_MODULATIONPARAMS = 0x8B,
    SX126x_RADIO_SET_PACKETPARAMS = 0x8C,
    SX126x_RADIO_GET_RXBUFFERSTATUS = 0x13,
    SX126x_RADIO_GET_PACKETSTATUS = 0x14,
    SX126x_RADIO_GET_RSSIINST = 0x15,
    SX126x_RADIO_SET_DIOIRQPARAMS = 0x08,
    SX126x_RADIO_GET_IRQSTATUS = 0x12,
    SX126x_RADIO_CLR_IRQSTATUS = 0x02,
    SX126x_RADIO_CALIBRATE = 0x89,
    SX126x_RADIO_SET_REGULATORMODE = 0x96,
    //SX126x_RADIO_SET_SAVECONTEXT = 0xD5,
    //SX126x_RADIO_SET_AUTOTX = 0x98,
    //SX126x_RADIO_SET_AUTOFS = 0x9E,
    //SX126x_RADIO_SET_LONGPREAMBLE = 0x9B,
    //SX126x_RADIO_SET_UARTSPEED = 0x9D,
    //SX126x_RADIO_SET_RANGING_ROLE = 0xA3,
    SX126x_RADIO_SET_DIO2_AS_RF_SWITCH_CTRL = 0x9D,
    SX126x_RADIO_SET_DIO3_AS_TCXO_CTRL = 0x97,

} SX126x_RadioCommands_t;

// TODO
typedef enum
{
    SX126x_IRQ_RADIO_NONE = 0x0000,
    SX126x_IRQ_TX_DONE = 0x0001,
    SX126x_IRQ_RX_DONE = 0x0002,
    SX126x_IRQ_SYNCWORD_VALID = 0x0004,
    SX126x_IRQ_SYNCWORD_ERROR = 0x0008,
    SX126x_IRQ_HEADER_VALID = 0x0010,
    SX126x_IRQ_HEADER_ERROR = 0x0020,
    SX126x_IRQ_CRC_ERROR = 0x0040,
    SX126x_IRQ_RANGING_SLAVE_RESPONSE_DONE = 0x0080,
    SX126x_IRQ_RANGING_SLAVE_REQUEST_DISCARDED = 0x0100,
    SX126x_IRQ_RANGING_MASTER_RESULT_VALID = 0x0200,
    SX126x_IRQ_RANGING_MASTER_TIMEOUT = 0x0400,
    SX126x_IRQ_RANGING_SLAVE_REQUEST_VALID = 0x0800,
    SX126x_IRQ_CAD_DONE = 0x1000,
    SX126x_IRQ_CAD_DETECTED = 0x2000,
    SX126x_IRQ_RX_TX_TIMEOUT = 0x4000,
    SX126x_IRQ_PREAMBLE_DETECTED = 0x8000,
    SX126x_IRQ_RADIO_ALL = 0xFFFF,
} SX126x_RadioIrqMasks_t;

// TODO
typedef enum
{
    SX126x_RADIO_DIO1 = 0x02,
    SX126x_RADIO_DIO2 = 0x04,
    SX126x_RADIO_DIO3 = 0x08,
} SX126x_RadioDios_t;

// TODO
typedef enum
{
    SX126x_RADIO_TICK_SIZE_0015_US = 0x00,
    SX126x_RADIO_TICK_SIZE_0062_US = 0x01,
    SX126x_RADIO_TICK_SIZE_1000_US = 0x02,
    SX126x_RADIO_TICK_SIZE_4000_US = 0x03,
} SX126x_RadioTickSizes_t;
