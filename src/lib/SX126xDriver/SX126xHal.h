#pragma once

/*
  ______                              _
 / _____)             _              | |
( (____  _____ ____ _| |_ _____  ____| |__
 \____ \| ___ |    (_   _) ___ |/ ___)  _ \
 _____) ) ____| | | || |_| ____( (___| | | |
(______/|_____)_|_|_| \__)_____)\____)_| |_|
    (C)2015 Semtech

Description: Handling of the node configuration protocol

License: Revised BSD License, see LICENSE.TXT file include in the project

Maintainer: Miguel Luis and Gregory Cristian

Heavily modified/simplified by Alessandro Carcione 2020 for ELRS project
*/

#include "SX126xRegs.h"
#include "SX126x.h"

enum SX126x_BusyState_
{
    SX126x_NOT_BUSY = true,
    SX126x_BUSY = false,
};

class SX126xHal
{
public:
    static SX126xHal *instance;

    SX126xHal();

    void init();
    void end();
    void reset();

    void ICACHE_RAM_ATTR setNss(uint8_t radioNumber, bool state);

    void ICACHE_RAM_ATTR WriteCommand(SX126x_RadioCommands_t command, uint8_t val, SX126x_Radio_Number_t radioNumber, uint32_t busyDelay = 15);
    void ICACHE_RAM_ATTR WriteCommand(SX126x_RadioCommands_t opcode, uint8_t *buffer, uint8_t size, SX126x_Radio_Number_t radioNumber, uint32_t busyDelay = 15);
    void ICACHE_RAM_ATTR WriteRegister(uint16_t address, uint8_t *buffer, uint8_t size, SX126x_Radio_Number_t radioNumber);
    void ICACHE_RAM_ATTR WriteRegister(uint16_t address, uint8_t value, SX126x_Radio_Number_t radioNumber);

    void ICACHE_RAM_ATTR ReadCommand(SX126x_RadioCommands_t opcode, uint8_t *buffer, uint8_t size, SX126x_Radio_Number_t radioNumber);
    void ICACHE_RAM_ATTR ReadRegister(uint16_t address, uint8_t *buffer, uint8_t size, SX126x_Radio_Number_t radioNumber);
    uint8_t ICACHE_RAM_ATTR ReadRegister(uint16_t address, SX126x_Radio_Number_t radioNumber);

    void ICACHE_RAM_ATTR WriteBuffer(uint8_t offset, uint8_t *buffer, uint8_t size, SX126x_Radio_Number_t radioNumber); // Writes and Reads to FIFO
    void ICACHE_RAM_ATTR ReadBuffer(uint8_t offset, uint8_t *buffer, uint8_t size, SX126x_Radio_Number_t radioNumber);

    bool ICACHE_RAM_ATTR WaitOnBusy(SX126x_Radio_Number_t radioNumber);

    void ICACHE_RAM_ATTR TXenable(SX126x_Radio_Number_t radioNumber);
    void ICACHE_RAM_ATTR RXenable();
    void ICACHE_RAM_ATTR TXRXdisable();

    static ICACHE_RAM_ATTR void dioISR_1();
    static ICACHE_RAM_ATTR void dioISR_2();
    void (*IsrCallback_1)(); //function pointer for callback
    void (*IsrCallback_2)(); //function pointer for callback

    uint32_t BusyDelayStart;
    uint32_t BusyDelayDuration;
    void BusyDelay(uint32_t duration)
    {
        if (GPIO_PIN_BUSY == UNDEF_PIN)
        {
            BusyDelayStart = micros();
            BusyDelayDuration = duration;
        }
    }
};
