/* 
 * File:   irtx.h
 * Author: philippe
 *
 * Created on February 22, 2014, 5:01 PM
 */

#ifndef IRTX_H
#define	IRTX_H

#ifdef __IRTX_C_
//#define __debug__
#include "debug.h"
#endif

#include <stdint.h>
#include <xc.h>

#include "ir.h"

#define mSetTimer(value) \
    PR3 = mTimer0_us(value) >> 16; \
    PR2 = mTimer0_us(value) & 0x0000FFFF; \

#define mTimer0_us(value)    ((uint32_t) value*2)
#define mPWM_kHz(value)    ((uint16_t) (16000/value))

#define rDuty OC1R
#define rFrequency OC1RS
#define irtxTimerInt IEC0bits.T3IE
#define irtxTimerFlag IFS0bits.T3IF

#define IRTX_DEFAULT_Frequency  36 // khz    
#define IRTX_DEFAULT_Duty       50 // %    

void irtxSend(void);
void intIrTx(void);
void irtxInit (void);
void irtx_on (void);
void irtx_off (void);
void irtx_int_space_code(void);
void irtx_int_raw_code(void);
//void irtx_send_raw_code(uint8_t offset);
void irtx_send_raw_code(ir_raw_code_t rawcode);
void irtx_set_frequency_duty(uint8_t frequency, uint8_t duty);

typedef enum {HEADER, CODE, TRAIL} irPhase_t;
typedef enum {PULSE,RAW} irtx_mode_t;

typedef struct __attribute__((packed)) irtxConfig_T {
    uint32_t irCode;
    uint32_t irMask;

    uint16_t headerPulse;
    uint16_t headerSpace;
    uint16_t dataOnePulse;
    uint16_t dataOneSpace;
    uint16_t dataZeroPulse;
    uint16_t dataZeroSpace;
    uint16_t trailerPulse;
    uint16_t gapSpace;

    uint8_t repeat;
    uint8_t frequency;
    uint8_t duty;

} irtxConfig_T;

#include "system_config.h"

#ifndef __IRTX_C_
extern irtxConfig_T irtxParameters;
extern ir_raw_code_t irtx_raw_code;
#endif

#endif	/* IRTX_H */




// No used
#if 0
    if (((join16in32(PR3,PR2) > join16in32(TMR3,TMR2))) && irtxTimerInt) {
        rDuty = 0;
        irtxTimerInt = 0;
        printf("End RAW(TO)\n");
        IFS0bits.IC1IF = 0;
        IEC0bits.IC1IE = 1;        
    }
#endif