/* 
 * File:   ledmacros.h
 * Author: philippe
 *
 * Created on May 2, 2016, 10:04 PM
 */

#ifndef LEDMACROS_H
#define	LEDMACROS_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <xc.h>
    
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


#ifdef	__cplusplus
}
#endif

#endif	/* LEDMACROS_H */

