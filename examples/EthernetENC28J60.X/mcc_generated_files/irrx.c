#define	IRRX_C
#include "irrx.h"
#include "irtx.h"

uint8_t write_offset = 0;
uint32_t rx_stack[IR_FIFO_LENGTH];
uint32_t irrx_lasttime;
bool irrx_is_timeout = true;

void ir_sync_rx_tx(void) {
    if (irrx_input_is_up()) {
        irtx_on();
    } else {
        irtx_off();
    }    
}

void irrx_append_data_stack(uint32_t mydata){
    rx_stack[write_offset] = mydata;  
    write_offset = ((write_offset + 1u) & IR_FIFO_MASK);
}

uint32_t irrx_get_duration (void) {
    uint32_t currenttime, duration;
    
    currenttime = join16in32 (IC2BUF, IC1BUF);

    if (currenttime < irrx_lasttime) {
        duration = 0xffffffffu - irrx_lasttime + currenttime;
    } else {
        duration = currenttime - irrx_lasttime;
    }

    irrx_lasttime = currenttime;
    duration = duration >> 1;
    return duration;
}

char irrxString[256];

void irrx_print_fifo (void) {
    static uint8_t read_offset;
    static int i;
    
    if (!i) {
        irrx_reset_data_text();
    }
    
    while ((read_offset != write_offset) && (i<ItemPerLine)) {
        if (rx_stack[read_offset] >= IRRX_HEADER){
            irrx_flush_data_text();
            irrx_reset_data_text();
            i = 0; 
        }           
        irrx_append_data_text(rx_stack[read_offset]);
        read_offset = ((read_offset + 1u) & IR_FIFO_MASK);
        i++;
    }
    
    if ((i>=ItemPerLine) || (i && irrx_is_timeout))   {    
        irrx_flush_data_text();
        i = 0;
    }
}

void irrx_decode (void) {
    static uint8_t decoder_offset;
    static uint32_t result = 0;
    static uint8_t codelength = 0;
         
    while (decoder_offset != write_offset) {
        if (rx_stack[decoder_offset] >= IRRX_HEADER){
            if (codelength) {
                irrx_flush_data_code(result, codelength);
                result = 0;
                codelength = 0;
            }
        }        
        else if (!(decoder_offset & 1)){
            if (rx_stack[decoder_offset] >= IRRX_ONE) {
                result = result << 1;
                result++;
                codelength++;
            } else {
                result = result << 1;
                codelength++;
            }
        }
        decoder_offset = ((decoder_offset + 1u) & IR_FIFO_MASK);
    }
    
    if (codelength && irrx_is_timeout && (decoder_offset == write_offset)) {
        irrx_flush_data_code(result, codelength);
        result = 0;
        codelength = 0;            
    }
}

void irrx_init(void) {
    irrx_reset_data_text();
}

void irrx_reset_data_text(void){
    sprintf(irrxString, "rx: ");
}

void irrx_flush_data_code(uint32_t result, uint8_t codelength) {
    printf("Result: 0x%08lx | %d\n", result, codelength);
    
    if (result == 0x00141ebe)
        mLED_2_Toggle();
}

void irrx_flush_data_text(void){
    strcat(irrxString, "\n");
    //eTowerTCPPrint((uint8_t*) irrxString);        
    printf(irrxString);        
}

void irrx_append_data_text(uint32_t mydata){
    char irrxData[7];

    if (mydata >= 10000)
        sprintf(irrxData, "---- ");
    else    
        sprintf(irrxData, "%4lu ", mydata);
    
    strcat(irrxString, irrxData);    
}

void irrx_task (void) {
    uint32_t currenttime, duration;
    
    //Watchdog
    //Compute duration in ms
    currenttime = join16in32(IC2TMR, IC1TMR);
    if (currenttime < irrx_lasttime) {
        duration = 0xffffffffu - irrx_lasttime + currenttime;
    } else {
        duration = currenttime - irrx_lasttime;
    }
    duration = duration >> 1;    
    
    if ((duration >= IRRX_TIMEOUT) && !irrx_is_timeout){
        irrx_is_timeout = true;
    }
  
    //Print
    //irrx_print_fifo();
    irrx_decode();
}

void irrx_echo (void) {
    static uint8_t echo_offset;

    //Enregistrer le code dans un nouveau tableau et émettre
    
    while (echo_offset != write_offset) {
        if (!(echo_offset & 1)){
        }
        echo_offset = ((echo_offset + 1u) & IR_FIFO_MASK);
    }
}

