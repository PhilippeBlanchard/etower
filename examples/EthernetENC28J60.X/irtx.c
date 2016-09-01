#define __IRTX_C_

#include "irtx.h"
#include "irrx.h"

extern uint32_t rx_stack[IR_FIFO_LENGTH];
ir_raw_code_t irtx_raw_code;
uint8_t irtx_raw_offset;

uint8_t tx_offset;

irtx_mode_t irtx_mode;
uint16_t    irtx_frequency;
uint16_t    irtx_duty;        

irtxConfig_T irtxParameters;
irPhase_t irtxPhase;
uint32_t irtxMaskBackup;
uint16_t irtxNextDuty;

uint16_t dutyOnValue;

void irtxInit (void) {
    DEBUG_MACRO_PRINT_FUNTION
            
    irtx_mode = PULSE;
    rDuty = 0;
    irtx_set_frequency_duty(36,50);
}

void irtx_on (void) {
    DEBUG_MACRO_PRINT_FUNTION
            
    rDuty = irtx_duty;    
}

void irtx_off (void) {
    DEBUG_MACRO_PRINT_FUNTION
            
    rDuty = 0;    
}

void irtxSend (void) {
    DEBUG_MACRO_PRINT_FUNTION
    
    irtx_mode = PULSE;
    irtxMaskBackup = irtxParameters.irMask;
    irtxPhase = HEADER;
    rFrequency = mPWM_kHz(irtxParameters.frequency);
    dutyOnValue = rFrequency * irtxParameters.duty / 100;
    irtxNextDuty = dutyOnValue;

    mSetTimer(100000l);
    TMR2 = 0;
    TMR3 = 0;
    irtxTimerInt = 1;
}

#if 0
void irtx_send_raw_code(uint8_t offset) {
    int i;
    irtx_mode = RAW;
    tx_offset = offset;
    
    irtx_raw_offset = 0;
    
    rFrequency = IRTX_DEFAULT_Frequency;
    rDuty = 0;
#if 0
    while ((rx_stack[offset] < IRRX_TIMEOUT) && rx_stack[offset]) {
        printf("[%3d]->[%4ld]\n",offset, rx_stack[offset]);
        offset = ((offset+1) & IR_FIFO_MASK);
        i++;
        if(!i) break;
    }
#endif
    
    irtxNextDuty = IRTX_DEFAULT_Duty;

    mSetTimer(100000l);
    TMR2 = 0;
    TMR3 = 0;
    irtxTimerInt = 1;
}
#endif

void irtx_send_raw_code(ir_raw_code_t rawcode) {

    DEBUG_MACRO_PRINT_FUNTION
            
    irtx_mode = RAW;
    irtx_raw_code = rawcode;

    irtxNextDuty = irtx_duty;
    
    IEC0bits.IC1IE = 0;
    
    mSetTimer(100000l);
    TMR2 = 0;
    TMR3 = 0;
    irtxTimerInt = 1;
}

void intIrTx()
{
    switch(irtx_mode) {
        case PULSE:
            irtx_int_space_code();
        break;
        case RAW:
            irtx_int_raw_code();
        break;
        default:
            rDuty = 0;
    }
}

void irtx_int_space_code () {
    rDuty = irtxNextDuty;
    switch (irtxPhase) {
        case HEADER:
            if (irtxNextDuty) {
                mSetTimer(irtxParameters.headerPulse);
            } else {
                irtxPhase = CODE;
                mSetTimer(irtxParameters.headerSpace);
            }
            break;

        case CODE:
            if (irtxNextDuty) {
                if ( irtxParameters.irMask &  irtxParameters.irCode){
                     mSetTimer(irtxParameters.dataOnePulse);
                }
                else{
                     mSetTimer(irtxParameters.dataZeroPulse);
                }
            } else {
                if ( irtxParameters.irMask &  irtxParameters.irCode){
                     mSetTimer(irtxParameters.dataOneSpace);
                }
                else{
                     mSetTimer(irtxParameters.dataZeroSpace);
                }
                 irtxParameters.irMask =  irtxParameters.irMask >> 1;
                if (!irtxParameters.irMask) {
                   irtxPhase = TRAIL;
                }
            }
            break;

        case TRAIL:
            if (irtxNextDuty){
                mSetTimer(irtxParameters.trailerPulse);
                irtxParameters.repeat--;
            }
            else{
                if (irtxParameters.repeat){
                    mSetTimer(irtxParameters.gapSpace);
                    irtxParameters.irMask =  irtxMaskBackup;
                    irtxPhase = CODE;
                } else {
                    irtxTimerInt = 0;
                }
            }
            break;
    }
    
    // Prepare next state
    if (irtxNextDuty)
        irtxNextDuty = 0;
    else
        irtxNextDuty = dutyOnValue;    
}

void irtx_int_raw_code() {
    static uint8_t i = 0;
    rDuty = irtxNextDuty;

    if (i < irtx_raw_code.length) {

        mSetTimer(irtx_raw_code.code[i]);
        i++;
        
        if ((i & 1) | (i>=irtx_raw_code.length)){
            irtxNextDuty = 0;
        } else {
            irtxNextDuty = irtx_duty;
        }
        
    } else {
        rDuty = 0;
        irtxTimerInt = 0;
        printf("End RAW -> %u\n", i);
        i=0;
        IFS0bits.IC1IF = 0;
        IEC0bits.IC1IE = 1;
    }
}

void irtx_set_frequency_duty(uint8_t frequency, uint8_t duty) {
    DEBUG_MACRO_PRINT_FUNTION
                
    irtx_frequency = mPWM_kHz(frequency);
    irtx_duty = ((uint16_t) irtx_frequency * duty) / 100;
    rFrequency = irtx_frequency;
}