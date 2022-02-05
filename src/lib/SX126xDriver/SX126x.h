#pragma once

#include "SX126xRegs.h"
#include "SX126xHal.h"

#ifdef PLATFORM_ESP8266
#include <cstdint>
#endif

class SX126xDriver
{

public:
    static SX126xDriver *instance;
    SX126xDriver();
    ///////Callback Function Pointers/////
    static void inline nullCallback(void);

    static void (*RXdoneCallback)(); //function pointer for callback
    static void (*TXdoneCallback)(); //function pointer for callback

    static void (*TXtimeout)(); //function pointer for callback
    static void (*RXtimeout)(); //function pointer for callback

///////////Radio Variables////////
    #define TXRXBuffSize 16
    const uint8_t TXbuffLen = TXRXBuffSize;
    const uint8_t RXbuffLen = TXRXBuffSize;

    static volatile WORD_ALIGNED_ATTR uint8_t TXdataBuffer[TXRXBuffSize];
    static volatile WORD_ALIGNED_ATTR uint8_t RXdataBuffer[TXRXBuffSize];

    bool headerExplMode = false;
    bool crcEnabled = false;

    //// Parameters ////
    uint8_t PayloadLength = 8; // Dummy default value which is overwritten during setup.
    uint32_t currFreq = 0; // leave as 0 to ensure that it gets set
    uint8_t currSyncWord = SX127X_SYNC_WORD;
    uint8_t currPreambleLen = 0;
    SX126x_Bandwidth currBW = SX126x_BW_125_00_KHZ; //default values from datasheet
    SX126x_SpreadingFactor currSF = SX126x_SF_7;
    SX126x_CodingRate currCR = SX126x_CR_4_5;
    SX126x_RadioOPmodes currOpmode = SX126x_OPMODE_SLEEP;
    uint8_t currPWR = 0b0000;
    SX126x_ModulationModes ModFSKorLoRa = SX126x_OPMODE_LORA;
    bool IQinverted = false;
    ///////////////////////////////////

    /////////////Packet Stats//////////
    int8_t LastPacketRSSI;
    int8_t LastPacketSNR;
    uint32_t TimeOnAir;
    uint32_t TXstartMicros;
    uint32_t TXspiTime;
    uint32_t HeadRoom;
    uint32_t LastTXdoneMicros;
    uint32_t TXdoneMicros;
    /////////////////////////////////

    ////////////////Configuration Functions/////////////
    bool Begin();
    void End();
    bool DetectChip();
    void Config(SX126x_Bandwidth bw, SX126x_SpreadingFactor sf, SX126x_CodingRate cr, uint32_t freq, uint8_t preambleLen, uint8_t syncWord, bool InvertIQ, uint8_t PayloadLength);
    void Config(SX126x_Bandwidth bw, SX126x_SpreadingFactor sf, SX126x_CodingRate cr, uint32_t freq, uint8_t preambleLen, bool InvertIQ, uint8_t PayloadLength);
    void SetMode(SX126x_RadioOPmodes mode);
    void SetTxIdleMode() { SetMode(SX126x_OPMODE_STANDBY); } // set Idle mode used when switching from RX to TX
    void ConfigLoraDefaults();

    void SetBandwidthCodingRate(SX126x_Bandwidth bw, SX126x_CodingRate cr);
    void SetSyncWord(uint8_t syncWord);
    void SetOutputPower(uint8_t Power);
    void SetOutputPowerMax() { SetOutputPower(0b1111); };
    void SetPreambleLength(uint8_t PreambleLen);
    void SetSpreadingFactor(SX126x_SpreadingFactor sf);

    uint32_t GetCurrBandwidth();
    uint32_t GetCurrBandwidthNormalisedShifted();

    #define FREQ_STEP 61.03515625
    void SetFrequencyHz(uint32_t freq);
    void SetFrequencyReg(uint32_t freq);
    int32_t GetFrequencyError();
    bool GetFrequencyErrorbool();
    void SetPPMoffsetReg(int32_t offset);

    ////////////////////////////////////////////////////

    /////////////////Utility Funcitons//////////////////
    uint8_t GetIrqFlags();
    void ClearIrqFlags();

    //////////////RX related Functions/////////////////

    //uint8_t RunCAD();

    uint8_t UnsignedGetLastPacketRSSI();
    int8_t GetLastPacketRSSI();
    int8_t GetLastPacketSNR();
    int8_t GetCurrRSSI();

    ////////////Non-blocking TX related Functions/////////////////
    void TXnb();
    /////////////Non-blocking RX related Functions///////////////
    void RXnb();

private:
    static void ICACHE_RAM_ATTR IsrCallback();
    void RXnbISR(); // ISR for non-blocking RX routine
    void TXnbISR(); // ISR for non-blocking TX routine
};
