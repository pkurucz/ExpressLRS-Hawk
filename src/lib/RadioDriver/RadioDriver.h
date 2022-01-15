#ifndef _RADIODRIVER_H
#define _RADIODRIVER_H

//#if defined(Regulatory_Domain_AU_915) || defined(Regulatory_Domain_EU_868) || defined(Regulatory_Domain_IN_866) || defined(Regulatory_Domain_FCC_915) || defined(Regulatory_Domain_AU_433) || defined(Regulatory_Domain_EU_433)
#if defined(SX127x)
#include "SX127xDriver.h"
#define RadioDriver SX127xDriver

//#elif defined(Regulatory_Domain_ISM_2400)
#elif defined(SX1280)
#include "SX1280Driver.h"
#define RadioDriver SX1280Driver

//#elif defined(Regulatory_Domain_FCC_433)
#elif defined(SX126x)
#include "SX126xDriver.h"
#define RadioDriver SX126xDriver

#else
#error "Radio configuration is not valid!"
#endif

extern RadioDriver Radio;

#endif /* ifndef _RADIODRIVER_H */
