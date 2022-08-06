#include "SX126xRegs.h"
#include "SX126xHal.h"
#include "SX126x.h"
#include "logging.h"

SX126xHal hal;
SX126xDriver *SX126xDriver::instance = NULL;

//DEBUG_SX126x_OTA_TIMING

/* Steps for startup

1. If not in STDBY_RC mode, then go to this mode by sending the command:
SetStandby(STDBY_RC)

2. Define the LoRa® packet type by sending the command:
SetPacketType(PACKET_TYPE_LORA)

3. Define the RF frequency by sending the command:
SetRfFrequency(rfFrequency)
The LSB of rfFrequency is equal to the PLL step i.e. 52e6/2^18 Hz. SetRfFrequency() defines the Tx frequency.

4. Indicate the addresses where the packet handler will read (txBaseAddress in Tx) or write (rxBaseAddress in Rx) the first
byte of the data payload by sending the command:
SetBufferBaseAddress(txBaseAddress, rxBaseAddress)
Note:
txBaseAddress and rxBaseAddress are offset relative to the beginning of the data memory map.

5. Define the modulation parameter signal BW SF CR
*/

#if defined(DEBUG_SX126x_OTA_TIMING)
static uint32_t beginTX;
static uint32_t endTX;
#endif

/*
 * Period Base from table 11-24, page 79 datasheet rev 3.2
 * SX126x_RADIO_TICK_SIZE_0015_US = 15625 nanos
 * SX126x_RADIO_TICK_SIZE_0062_US = 62500 nanos
 * SX126x_RADIO_TICK_SIZE_1000_US = 1000000 nanos
 * SX126x_RADIO_TICK_SIZE_4000_US = 4000000 nanos
 */
#define RX_TIMEOUT_PERIOD_BASE SX126x_RADIO_TICK_SIZE_0015_US
#define RX_TIMEOUT_PERIOD_BASE_NANOS 15625

#ifdef USE_SX126x_DCDC
    #ifndef OPT_USE_SX126x_DCDC
        #define OPT_USE_SX126x_DCDC true
    #endif
#else
    #define OPT_USE_SX126x_DCDC false
#endif

SX126xDriver::SX126xDriver(): SX12xxDriverCommon()
{
    instance = this;
}

void SX126xDriver::End()
{
    SetMode(SX126x_MODE_SLEEP, SX126x_Radio_All);
    hal.end();
    RemoveCallbacks();
    currFreq = (uint32_t)((double)2400000000 / (double)FREQ_STEP);
    PayloadLength = 8; // Dummy default value which is overwritten during setup.
}

bool SX126xDriver::Begin()
{
    hal.init();
    hal.IsrCallback_1 = &SX126xDriver::IsrCallback_1;
    hal.IsrCallback_2 = &SX126xDriver::IsrCallback_2;

    hal.reset();
    DBGLN("SX126x Begin");

    SetMode(SX126x_MODE_STDBY_RC, SX126x_Radio_All); // Put in STDBY_RC mode.  Must be SX126x_MODE_STDBY_RC for SX126x_RADIO_SET_REGULATORMODE to be set.

    uint16_t firmwareRev = (((hal.ReadRegister(REG_LR_FIRMWARE_VERSION_MSB, SX126x_Radio_1)) << 8) | (hal.ReadRegister(REG_LR_FIRMWARE_VERSION_MSB + 1, SX126x_Radio_1)));
    DBGLN("Read Vers sx126x #1: %d", firmwareRev);
    if ((firmwareRev == 0) || (firmwareRev == 65535))
    {
        // SPI communication failed, just return without configuration
        return false;
    }

    if (GPIO_PIN_NSS_2 != UNDEF_PIN)
    {
        firmwareRev = (((hal.ReadRegister(REG_LR_FIRMWARE_VERSION_MSB, SX126x_Radio_2)) << 8) | (hal.ReadRegister(REG_LR_FIRMWARE_VERSION_MSB + 1, SX126x_Radio_2)));
        DBGLN("Read Vers sx126x #2: %d", firmwareRev);
        if ((firmwareRev == 0) || (firmwareRev == 65535))
        {
            // SPI communication failed, just return without configuration
            return false;
        }

        hal.WriteRegister(0x0891, (hal.ReadRegister(0x0891, SX126x_Radio_2) | 0xC0), SX126x_Radio_2);   //default is low power mode, switch to high sensitivity instead
    }

    hal.WriteRegister(0x0891, (hal.ReadRegister(0x0891, SX126x_Radio_1) | 0xC0), SX126x_Radio_1);   //default is low power mode, switch to high sensitivity instead
//PTK TODO:    hal.WriteCommand(SX126x_RADIO_SET_AUTOFS, 0x01, SX126x_Radio_All);                              //Enable auto FS
#if defined(USE_SX126x_DCDC)
    if (OPT_USE_SX126x_DCDC)
    {
        hal.WriteCommand(SX126x_RADIO_SET_REGULATORMODE, SX126x_USE_DCDC, SX126x_Radio_All);        // Enable DCDC converter instead of LDO
    }
#endif

    return true;
}

void SX126xDriver::Config(uint8_t bw, uint8_t sf, uint8_t cr, uint32_t regfreq,
                          uint8_t PreambleLength, bool InvertIQ, uint8_t _PayloadLength, uint32_t interval)
{
    uint8_t const mode = SX126x_PACKET_TYPE_LORA;

    PayloadLength = _PayloadLength;
    IQinverted = InvertIQ;
    packet_mode = mode;
    SetMode(SX126x_MODE_STDBY_RC, SX126x_Radio_All);
    hal.WriteCommand(SX126x_RADIO_SET_PACKETTYPE, mode, SX126x_Radio_All, 20);

    DBG("Config LoRa ");
    ConfigModParamsLoRa(bw, sf, cr);
#if defined(DEBUG_FREQ_CORRECTION)
    SX126x_RadioLoRaPacketLengthsModes_t packetLengthType = SX126x_LORA_PACKET_VARIABLE_LENGTH;
#else
    SX126x_RadioLoRaPacketLengthsModes_t packetLengthType = SX126x_LORA_PACKET_FIXED_LENGTH;
#endif
    SetPacketParamsLoRa(PreambleLength, packetLengthType, _PayloadLength, InvertIQ);

    SetFrequencyReg(regfreq);
    SetRxTimeoutUs(interval);

    uint8_t dio1Mask = SX126x_IRQ_TX_DONE | SX126x_IRQ_RX_DONE;
    uint8_t irqMask  = SX126x_IRQ_TX_DONE | SX126x_IRQ_RX_DONE | SX126x_IRQ_SYNCWORD_VALID | SX126x_IRQ_SYNCWORD_ERROR | SX126x_IRQ_CRC_ERROR;
    SetDioIrqParams(irqMask, dio1Mask);
}

void SX126xDriver::SetRxTimeoutUs(uint32_t interval)
{
    if (interval)
    {
        timeout = interval * 1000 / RX_TIMEOUT_PERIOD_BASE_NANOS; // number of periods for the SX126x to timeout
    }
    else
    {
        timeout = 0xFFFF;   // no timeout, continuous mode
    }
}

void SX126xDriver::SetOutputPower(int8_t power)
{
    if (power < -18) power = -18;
    else if (13 < power) power = 13;
    uint8_t buf[2] = {(uint8_t)(power + 18), (uint8_t)SX126x_RADIO_RAMP_04_US};
    hal.WriteCommand(SX126x_RADIO_SET_TXPARAMS, buf, sizeof(buf), SX126x_Radio_All);
    DBGLN("SetPower: %d", buf[0]);
    return;
}

void SX126xDriver::SetMode(SX126x_RadioOperatingModes_t OPmode, SX126x_Radio_Number_t radioNumber)
{
    /*
    Comment out since it is difficult to keep track of dual radios.
    When checking SPI it is also useful to see every possible SPI transaction to make sure it fits when required.
    */
    // if (OPmode == currOpmode)
    // {
    //    return;
    // }

    WORD_ALIGNED_ATTR uint8_t buf[3];
    switch (OPmode)
    {

    case SX126x_MODE_SLEEP:
        hal.WriteCommand(SX126x_RADIO_SET_SLEEP, (uint8_t)0x01, radioNumber);
        break;

    case SX126x_MODE_CALIBRATION:
        break;

    case SX126x_MODE_STDBY_RC:
        hal.WriteCommand(SX126x_RADIO_SET_STANDBY, SX126x_STDBY_RC, radioNumber, 1500);
        break;

    // The DC-DC supply regulation is automatically powered in STDBY_XOSC mode.
    case SX126x_MODE_STDBY_XOSC:
        hal.WriteCommand(SX126x_RADIO_SET_STANDBY, SX126x_STDBY_XOSC, radioNumber, 50);
        break;

    case SX126x_MODE_FS:
        hal.WriteCommand(SX126x_RADIO_SET_FS, (uint8_t)0x00, radioNumber, 70);
        break;

    case SX126x_MODE_RX:
        buf[0] = RX_TIMEOUT_PERIOD_BASE;
        buf[1] = timeout >> 8;
        buf[2] = timeout & 0xFF;
        hal.WriteCommand(SX126x_RADIO_SET_RX, buf, sizeof(buf), radioNumber, 100);
        break;

    case SX126x_MODE_TX:
        //uses timeout Time-out duration = periodBase * periodBaseCount
        buf[0] = RX_TIMEOUT_PERIOD_BASE;
        buf[1] = 0xFF; // no timeout set for now
        buf[2] = 0xFF; // TODO dynamic timeout based on expected onairtime
        hal.WriteCommand(SX126x_RADIO_SET_TX, buf, sizeof(buf), radioNumber, 100);
        break;

    case SX126x_MODE_CAD:
        break;

    default:
        break;
    }

    currOpmode = OPmode;
}

void SX126xDriver::ConfigModParamsLoRa(uint8_t bw, uint8_t sf, uint8_t cr)
{
    // Care must therefore be taken to ensure that modulation parameters are set using the command
    // SetModulationParam() only after defining the packet type SetPacketType() to be used

    WORD_ALIGNED_ATTR uint8_t rfparams[3] = {sf, bw, cr};

    hal.WriteCommand(SX126x_RADIO_SET_MODULATIONPARAMS, rfparams, sizeof(rfparams), SX126x_Radio_All, 25);

    switch (sf)
    {
    case SX126x_LORA_SF5:
    case SX126x_LORA_SF6:
        hal.WriteRegister(SX126x_REG_SF_ADDITIONAL_CONFIG, 0x1E, SX126x_Radio_All); // for SF5 or SF6
        break;
    case SX126x_LORA_SF7:
    case SX126x_LORA_SF8:
        hal.WriteRegister(SX126x_REG_SF_ADDITIONAL_CONFIG, 0x37, SX126x_Radio_All); // for SF7 or SF8
        break;
    default:
        hal.WriteRegister(SX126x_REG_SF_ADDITIONAL_CONFIG, 0x32, SX126x_Radio_All); // for SF9, SF10, SF11, SF12
    }
    // Datasheet in LoRa Operation says "After SetModulationParams command:
    // In all cases 0x1 must be written to the Frequency Error Compensation mode register 0x093C"
    // However, this causes CRC errors for SF9 when using a high deviation TX (145kHz) and not using Explicit Header mode.
    // The default register value (0x1b) seems most compatible, so don't mess with it
    // InvertIQ=0 0x00=No reception 0x01=Poor reception w/o Explicit Header 0x02=OK 0x03=OK
    // InvertIQ=1 0x00, 0x01, 0x02, and 0x03=Poor reception w/o Explicit Header
    // hal.WriteRegister(SX126x_REG_FREQ_ERR_CORRECTION, 0x03, SX126x_Radio_All);
}

void SX126xDriver::SetPacketParamsLoRa(uint8_t PreambleLength, SX126x_RadioLoRaPacketLengthsModes_t HeaderType,
                                       uint8_t PayloadLength, uint8_t InvertIQ)
{
    uint8_t buf[7];

    buf[0] = PreambleLength;
    buf[1] = HeaderType;
    buf[2] = PayloadLength;
    buf[3] = SX126x_LORA_CRC_OFF;
    buf[4] = InvertIQ ? SX126x_LORA_IQ_INVERTED : SX126x_LORA_IQ_NORMAL;
    buf[5] = 0x00;
    buf[6] = 0x00;

    hal.WriteCommand(SX126x_RADIO_SET_PACKETPARAMS, buf, sizeof(buf), SX126x_Radio_All, 20);

    // FEI only triggers in Lora mode when the header is present :(
    modeSupportsFei = HeaderType == SX126x_LORA_PACKET_VARIABLE_LENGTH;
}

void ICACHE_RAM_ATTR SX126xDriver::SetFrequencyHz(uint32_t freq)
{
    uint32_t regfreq = (uint32_t)((double)freq / (double)FREQ_STEP);

    SetFrequencyReg(regfreq);
}

void ICACHE_RAM_ATTR SX126xDriver::SetFrequencyReg(uint32_t regfreq)
{
    WORD_ALIGNED_ATTR uint8_t buf[3] = {0};

    buf[0] = (uint8_t)((regfreq >> 16) & 0xFF);
    buf[1] = (uint8_t)((regfreq >> 8) & 0xFF);
    buf[2] = (uint8_t)(regfreq & 0xFF);

    hal.WriteCommand(SX126x_RADIO_SET_RFFREQUENCY, buf, sizeof(buf), SX126x_Radio_All);

    currFreq = regfreq;
}

void SX126xDriver::SetFIFOaddr(uint8_t txBaseAddr, uint8_t rxBaseAddr)
{
    uint8_t buf[2];

    buf[0] = txBaseAddr;
    buf[1] = rxBaseAddr;
    hal.WriteCommand(SX126x_RADIO_SET_BUFFERBASEADDRESS, buf, sizeof(buf), SX126x_Radio_All);
}

void SX126xDriver::SetDioIrqParams(uint16_t irqMask, uint16_t dio1Mask, uint16_t dio2Mask, uint16_t dio3Mask)
{
    uint8_t buf[8];

    buf[0] = (uint8_t)((irqMask >> 8) & 0x00FF);
    buf[1] = (uint8_t)(irqMask & 0x00FF);
    buf[2] = (uint8_t)((dio1Mask >> 8) & 0x00FF);
    buf[3] = (uint8_t)(dio1Mask & 0x00FF);
    buf[4] = (uint8_t)((dio2Mask >> 8) & 0x00FF);
    buf[5] = (uint8_t)(dio2Mask & 0x00FF);
    buf[6] = (uint8_t)((dio3Mask >> 8) & 0x00FF);
    buf[7] = (uint8_t)(dio3Mask & 0x00FF);

    hal.WriteCommand(SX126x_RADIO_SET_DIOIRQPARAMS, buf, sizeof(buf), SX126x_Radio_All);
}

uint16_t ICACHE_RAM_ATTR SX126xDriver::GetIrqStatus(SX126x_Radio_Number_t radioNumber)
{
    uint8_t status[2];

    hal.ReadCommand(SX126x_RADIO_GET_IRQSTATUS, status, 2, radioNumber);
    return status[0] << 8 | status[1];
}

void ICACHE_RAM_ATTR SX126xDriver::ClearIrqStatus(uint16_t irqMask, SX126x_Radio_Number_t radioNumber)
{
    uint8_t buf[2];

    buf[0] = (uint8_t)(((uint16_t)irqMask >> 8) & 0x00FF);
    buf[1] = (uint8_t)((uint16_t)irqMask & 0x00FF);

    hal.WriteCommand(SX126x_RADIO_CLR_IRQSTATUS, buf, sizeof(buf), radioNumber);
}

void ICACHE_RAM_ATTR SX126xDriver::TXnbISR()
{
    currOpmode = SX126x_MODE_FS; // radio goes to FS after TX
#ifdef DEBUG_SX126x_OTA_TIMING
    endTX = micros();
    DBGLN("TOA: %d", endTX - beginTX);
#endif
    TXdoneCallback();
}

void ICACHE_RAM_ATTR SX126xDriver::TXnb(uint8_t * data, uint8_t size)
{
    if (currOpmode == SX126x_MODE_TX) //catch TX timeout
    {
        //DBGLN("Timeout!");
        SetMode(SX126x_MODE_FS, SX126x_Radio_All);
        TXnbISR();
        return;
    }

    if (GPIO_PIN_NSS_2 != UNDEF_PIN)
    {
        // Make sure the unused radio is in FS mode and will not receive the tx packet.
        if (lastSuccessfulPacketRadio == SX126x_Radio_1)
        {
            instance->SetMode(SX126x_MODE_FS, SX126x_Radio_2);
        }
        else
        {
            instance->SetMode(SX126x_MODE_FS, SX126x_Radio_1);
        }
    }

    hal.TXenable(lastSuccessfulPacketRadio); // do first to allow PA stablise
    hal.WriteBuffer(0x00, data, size, lastSuccessfulPacketRadio); //todo fix offset to equal fifo addr
    instance->SetMode(SX126x_MODE_TX, lastSuccessfulPacketRadio);

#ifdef DEBUG_SX126x_OTA_TIMING
    beginTX = micros();
#endif
}

bool ICACHE_RAM_ATTR SX126xDriver::RXnbISR(uint16_t irqStatus, SX126x_Radio_Number_t radioNumber)
{
    // In continuous receive mode, the device stays in Rx mode
    if (timeout != 0xFFFF)
    {
        // From table 11-28, pg 81 datasheet rev 3.2
        // upon successsful receipt, when the timer is active or in single mode, it returns to STDBY_RC
        // but because we have AUTO_FS enabled we automatically transition to state SX126x_MODE_FS
        currOpmode = SX126x_MODE_FS;
    }

    rx_status fail = SX12XX_RX_OK;
#if 0
    // The SYNCWORD_VALID bit isn't set on LoRa, it has no synch (sic) word, and CRC is only on for FLRC
    if (packet_mode == SX126x_PACKET_TYPE_FLRC)
    {
        fail = ((irqStatus & SX126x_IRQ_CRC_ERROR) ? SX12XX_RX_CRC_FAIL : SX12XX_RX_OK) |
               ((irqStatus & SX126x_IRQ_SYNCWORD_VALID) ? SX12XX_RX_OK : SX12XX_RX_SYNCWORD_ERROR) |
               ((irqStatus & SX126x_IRQ_SYNCWORD_ERROR) ? SX12XX_RX_SYNCWORD_ERROR : SX12XX_RX_OK);
    }
#endif
    if (fail == SX12XX_RX_OK)
    {
        uint8_t const FIFOaddr = GetRxBufferAddr(radioNumber);
        hal.ReadBuffer(FIFOaddr, RXdataBuffer, PayloadLength, radioNumber);
    }

    return RXdoneCallback(fail);
}

void ICACHE_RAM_ATTR SX126xDriver::RXnb()
{
    hal.RXenable();
    SetMode(SX126x_MODE_RX, SX126x_Radio_All);
}

uint8_t ICACHE_RAM_ATTR SX126xDriver::GetRxBufferAddr(SX126x_Radio_Number_t radioNumber)
{
    WORD_ALIGNED_ATTR uint8_t status[2] = {0};
    hal.ReadCommand(SX126x_RADIO_GET_RXBUFFERSTATUS, status, 2, radioNumber);
    return status[1];
}

void ICACHE_RAM_ATTR SX126xDriver::GetStatus(SX126x_Radio_Number_t radioNumber)
{
    uint8_t status = 0;
    hal.ReadCommand(SX126x_RADIO_GET_STATUS, (uint8_t *)&status, 1, radioNumber);
    DBGLN("Status: %x, %x, %x", (0b11100000 & status) >> 5, (0b00011100 & status) >> 2, 0b00000001 & status);
}

bool ICACHE_RAM_ATTR SX126xDriver::GetFrequencyErrorbool()
{
    // Only need the highest bit of the 20-bit FEI to determine the direction
    uint8_t feiMsb = hal.ReadRegister(SX126x_REG_LR_ESTIMATED_FREQUENCY_ERROR_MSB, lastSuccessfulPacketRadio);
    // fei & (1 << 19) and flip sign if IQinverted
    if (feiMsb & 0x08)
        return IQinverted;
    else
        return !IQinverted;
}

int8_t ICACHE_RAM_ATTR SX126xDriver::GetRssiInst()
{
    uint8_t status = 0;

    hal.ReadCommand(SX126x_RADIO_GET_RSSIINST, (uint8_t *)&status, 1, lastSuccessfulPacketRadio);
    return -(int8_t)(status / 2);
}

void ICACHE_RAM_ATTR SX126xDriver::GetLastPacketStats()
{
    uint8_t status[2];
    hal.ReadCommand(SX126x_RADIO_GET_PACKETSTATUS, status, 2, processingPacketRadio);
    // LoRa mode has both RSSI and SNR
    LastPacketRSSI = -(int8_t)(status[0] / 2);
    LastPacketSNRRaw = (int8_t)status[1];
    // https://www.mouser.com/datasheet/2/761/DS_SX126x-1_V2.2-1511144.pdf p84
    // need to subtract SNR from RSSI when SNR <= 0;
    int8_t negOffset = (LastPacketSNRRaw < 0) ? (LastPacketSNRRaw / RADIO_SNR_SCALE) : 0;
    LastPacketRSSI += negOffset;
}

void ICACHE_RAM_ATTR SX126xDriver::IsrCallback_1()
{
    instance->IsrCallback(SX126x_Radio_1);
}

void ICACHE_RAM_ATTR SX126xDriver::IsrCallback_2()
{
    instance->IsrCallback(SX126x_Radio_2);
}

void ICACHE_RAM_ATTR SX126xDriver::IsrCallback(SX126x_Radio_Number_t radioNumber)
{
    instance->processingPacketRadio = radioNumber;
    SX126x_Radio_Number_t irqClearRadio = radioNumber;

    uint16_t irqStatus = instance->GetIrqStatus(radioNumber);
    if (irqStatus & SX126x_IRQ_TX_DONE)
    {
        hal.TXRXdisable();
        instance->TXnbISR();
        irqClearRadio = SX126x_Radio_All;
    }
    else if (irqStatus & SX126x_IRQ_RX_DONE)
    {
        if (instance->RXnbISR(irqStatus, radioNumber))
        {
            instance->lastSuccessfulPacketRadio = radioNumber;
            irqClearRadio = SX126x_Radio_All; // Packet received so clear all radios and dont spend extra time retrieving data.
        }
    }
    else
    {
        return;
    }
    instance->ClearIrqStatus(SX126x_IRQ_RADIO_ALL, irqClearRadio);
}
