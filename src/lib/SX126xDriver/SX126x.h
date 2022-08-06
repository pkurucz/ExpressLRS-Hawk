#pragma once

#include "targets.h"
#include "SX126xRegs.h"
#include "SX126xHal.h"
#include "SX12xxDriverCommon.h"

#define RADIO_SNR_SCALE 4 // Units for LastPacketSNRRaw

class SX126xDriver: public SX12xxDriverCommon
{
public:
    static SX126xDriver *instance;


    ///////////Radio Variables////////
    uint16_t timeout = 0xFFFF;

    ///////////////////////////////////

    ////////////////Configuration Functions/////////////
    SX126xDriver();
    bool Begin();
    void End();
    void SetTxIdleMode() { SetMode(SX126x_MODE_FS, SX126x_Radio_All); }; // set Idle mode used when switching from RX to TX
    void Config(uint8_t bw, uint8_t sf, uint8_t cr, uint32_t freq,
                uint8_t PreambleLength, bool InvertIQ, uint8_t PayloadLength, uint32_t interval);
    void SetFrequencyHz(uint32_t freq);
    void SetFrequencyReg(uint32_t freq);
    void SetRxTimeoutUs(uint32_t interval);
    void SetOutputPower(int8_t power);


    bool GetFrequencyErrorbool();
    bool FrequencyErrorAvailable() const { return modeSupportsFei && (LastPacketSNRRaw > 0); }

    void TXnb(uint8_t * data, uint8_t size);
    void RXnb();

    uint16_t GetIrqStatus(SX126x_Radio_Number_t radioNumber);
    void ClearIrqStatus(uint16_t irqMask, SX126x_Radio_Number_t radioNumber);

    void GetStatus(SX126x_Radio_Number_t radioNumber);

    uint8_t GetRxBufferAddr(SX126x_Radio_Number_t radioNumber);
    int8_t GetRssiInst();
    void GetLastPacketStats();

private:
    SX126x_RadioOperatingModes_t currOpmode = SX126x_MODE_SLEEP;
    uint8_t packet_mode;
    bool modeSupportsFei;
    SX126x_Radio_Number_t processingPacketRadio;
    SX126x_Radio_Number_t lastSuccessfulPacketRadio = SX126x_Radio_1;

    void SetMode(SX126x_RadioOperatingModes_t OPmode, SX126x_Radio_Number_t radioNumber);
    void SetFIFOaddr(uint8_t txBaseAddr, uint8_t rxBaseAddr);

    // LoRa functions
    void ConfigModParamsLoRa(uint8_t bw, uint8_t sf, uint8_t cr);
    void SetPacketParamsLoRa(uint8_t PreambleLength, SX126x_RadioLoRaPacketLengthsModes_t HeaderType,
                             uint8_t PayloadLength, uint8_t InvertIQ);

    void SetDioIrqParams(uint16_t irqMask,
                         uint16_t dio1Mask=SX126x_IRQ_RADIO_NONE,
                         uint16_t dio2Mask=SX126x_IRQ_RADIO_NONE,
                         uint16_t dio3Mask=SX126x_IRQ_RADIO_NONE);

    static void IsrCallback_1();
    static void IsrCallback_2();
    static void IsrCallback(SX126x_Radio_Number_t radioNumber);
    bool RXnbISR(uint16_t irqStatus, SX126x_Radio_Number_t radioNumber); // ISR for non-blocking RX routine
    void TXnbISR(); // ISR for non-blocking TX routine
};
