#ifndef SYSTEMCONFIG_H
#define	SYSTEMCONFIG_H

#define mLED_1          LATAbits.LATA2
#define mGetLED_1()     mLED_1
#define mLED_1_On()     mLED_1 = 1
#define mLED_1_Off()    mLED_1 = 0
#define mLED_1_Toggle() mLED_1 = !mLED_1

#define mLED_2          LATAbits.LATA3
#define mGetLED_2()     mLED_2
#define mLED_2_On()     mLED_2 = 1
#define mLED_2_Off()    mLED_2 = 0
#define mLED_2_Toggle() mLED_2 = !mLED_2

#include "GenericTypeDefs.h"
#include "pin_manager.h"
#include "usb_config.h"
#include "usb_fonctions.h"

#endif /* SYSTEMCONFIG_H */