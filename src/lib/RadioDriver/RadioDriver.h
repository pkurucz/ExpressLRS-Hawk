#ifndef _RADIODRIVER_H
#define _RADIODRIVER_H

#if defined(RADIO_SX127X)
#include "SX127xDriver.h"
#define RadioDriver SX127xDriver

#elif defined(RADIO_SX1280)
#include "SX1280Driver.h"
#define RadioDriver SX1280Driver

#elif defined(RADIO_SX126X)
#include "SX126xDriver.h"
#define RadioDriver SX126xDriver

#else
#error "Radio configuration is not valid!"
#endif

extern RadioDriver Radio;

#endif /* ifndef _RADIODRIVER_H */
