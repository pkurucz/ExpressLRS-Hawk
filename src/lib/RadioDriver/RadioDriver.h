#ifndef _RADIODRIVER_H
#define _RADIODRIVER_H

#if defined(SX127x)
#include "SX127xDriver.h"
#define RadioDriver SX127xDriver

#elif defined(SX1280)
#include "SX1280Driver.h"
#define RadioDriver SX1280Driver

#elif defined(SX126x)
#include "SX126xDriver.h"
#define RadioDriver SX126xDriver

#else
#error "Radio configuration is not valid!"
#endif

extern RadioDriver Radio;

#endif /* ifndef _RADIODRIVER_H */
