#define	IRRX_C
#include "irrx.h"

uint8_t write_offset = 0;
uint8_t echo_offset = 0;
uint8_t read_offset;

uint32_t rx_stack[IR_FIFO_LENGTH];

uint32_t *irrx_stack_start, *irrx_stack_end;
uint32_t *irrx_raw_code_extract_ptr;
uint32_t *irrx_write_ptr;


uint32_t irrx_lasttime;

bool irrx_is_timeout = true;
bool irrx_echo_enabled = false;
bool irrx_sync_enabled = false;
uint8_t irrx_verbose = 0;
char irrxString[256];

extern uint8_t tx_offset;

// IRRX core functions
void irrx_init(void) {
    irrx_reset_data_text();
    irrx_stack_start = rx_stack;
    irrx_stack_end = irrx_stack_start + IR_FIFO_LENGTH - 1;
    irrx_write_ptr = irrx_stack_start;
}

void irrx_task (void) {
    uint32_t duration;
    
    //Watchdog
    duration = irrx_get_time_elapsed();        
    if ((duration >= IRRX_TIMEOUT) && !irrx_is_timeout){
        irrx_is_timeout = true;
        //Tag timeout in stream and keep sync
        irrx_append_data_stack(IRRX_TIMEOUT);               
        if (irrx_input_is_up() != is_odd(write_offset)) {
            irrx_append_data_stack(0);       
        }
        printf("Timeout=%lu\n",duration);
    }

    //if (irrx_echo_enabled) {
    //    if ((echo_offset != write_offset) && (duration >= IR_ECHO_DELAY)) {
    //        irrx_echo();
    //    }
    //}

    //Print
    if (irrx_verbose)
        irrx_print_fifo();
    
    irrx_extract_raw_code();
    ir_echo_rawcode_task();
    //irrx_decode();
}

void irrx_int(void) {
    if (irrx_sync_enabled)
        ir_sync_rx_tx();
    
    while (IC1CON1bits.ICBNE) {
        irrx_append_data_stack(irrx_get_duration());
    }       
}

void irrx_append_data_stack(uint32_t mydata){
    //For compatibility only. This line will be removed.
    write_offset = ((write_offset + 1u) & IR_FIFO_MASK);
    
    *irrx_write_ptr = mydata;    
    irrx_write_ptr++;
    if (irrx_write_ptr > irrx_stack_end)
        irrx_write_ptr = irrx_stack_start;
}

uint32_t irrx_get_duration (void) {
    uint32_t currenttime, duration;
    
    currenttime = join16in32 (IC2BUF, IC1BUF);

    if (currenttime < irrx_lasttime) {
        duration = 0xffffffffu - irrx_lasttime + currenttime;
    } else {
        duration = currenttime - irrx_lasttime;
    }
    duration = duration >> 1;
    
    //if (duration >= IRRX_ZERO) 
    irrx_lasttime = currenttime;

    return duration;
}

uint32_t irrx_get_time_elapsed (void) {
    return irrx_get_time_elapsed_since(irrx_lasttime);
}

uint32_t irrx_get_time_elapsed_since (uint32_t timestamp) {
    uint32_t currenttime, duration;
   
    currenttime = join16in32 (IC2TMR, IC1TMR);

    if (currenttime < timestamp) {
        duration = 0xffffffffu - timestamp + currenttime;
    } else {
        duration = currenttime - timestamp;
    }
    duration = duration >> 1;
    
    return duration;
}


// IRRX Verbose function
void irrx_print_fifo (void) {
    static int i;
    uint32_t duration;
    
    if (!i) {
        irrx_reset_data_text();
    }
    
    while ((read_offset != write_offset) && (i<ItemPerLine)) {
        duration = rx_stack[read_offset];
        irrx_append_data_text(duration);
        read_offset = ((read_offset + 1u) & IR_FIFO_MASK);        
        i++;
        
        if ((duration >= IRRX_GAP) && i) {
            irrx_flush_data_text();
            irrx_reset_data_text();
            i = 0; 
        }           
    }
    
    //if ((i>=ItemPerLine) || (i && irrx_is_timeout && (read_offset == write_offset))) {        
    if ((i>=ItemPerLine) || (i && irrx_is_timeout)) {    
        irrx_flush_data_text();
        i = 0;
    }
}

void irrx_reset_data_text(void){
    sprintf(irrxString, "[%3d] ", read_offset);
}

void irrx_flush_data_text(void){
    strcat(irrxString, "\n");
    //eTowerTCPPrint((uint8_t*) irrxString);
    printf(irrxString);
}

void irrx_append_data_text(uint32_t mydata){
    char irrxData[7];

    if (mydata >= 100000)
        sprintf(irrxData, "----- ");
    else    
        sprintf(irrxData, "%5lu ", mydata);

    strcat(irrxString, irrxData);    
}

void irrx_flush_data_code(uint32_t result, uint8_t codelength) {
    printf("Result: 0x%08lx | %d\n", result, codelength);
}

// IRRX Behavior management
void irrx_set_verbose(uint8_t level) {
    irrx_verbose = level;
}

void irrx_set_echo(bool state) {
    irrx_echo_enabled = state;
}

void irrx_set_sync(bool state) {
    irrx_sync_enabled = state;
}

// IRRX utility function
void ir_sync_rx_tx(void) {
    if (irrx_input_is_up()) {
        irtx_on();
        //mLED_2_On();
    } else {
        irtx_off();
        //mLED_2_Off();
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

void irrx_decode_space_encoded (ir_raw_code_t rawcode) {
    uint32_t result = 0;    
    uint8_t i;
    
    for (i=0; i< rawcode.length; i++) {
        if (rawcode.code[i] >= IRRX_HEADER){
        }        
        else if (i & 1){
            if (rawcode.code[i] >= IRRX_ONE) {
                result = result << 1;
                result++;
            } else {
                result = result << 1;
            }
        }
    }

    printf("IR code = 0x%08lx\n", result);
}

void irrx_echo (void) {
    IEC0bits.IC1IE = 0;
    mLED_2_On();
    printf("Echo code [%d]\n", echo_offset);
    //irtx_send_raw_code(echo_offset);
    echo_offset = write_offset;
}

void irrx_extract_raw_code(){
    static uint32_t *ptr;
    static ir_raw_code_t rawcode;
    static int i = 0;
    
    if (ptr < irrx_stack_start || ptr > irrx_stack_end){
        ptr = irrx_write_ptr;
        i = -1;
    }

    if (ptr != irrx_write_ptr) {
        if (i < 0) {
            if (*ptr > IRRX_TIMEOUT ) {
                i=0;
            }
        }
        else if (i < MAX_RAW_LENGTH) {
            rawcode.code[i] = *ptr;
            i++;
            if (*ptr > IRRX_GAP || *ptr == 0) {
                rawcode.length = i;
                irrx_handle_raw_code(rawcode);
                i = -1;                        
            }
        } 
        else {
            printf("[Error] Code Overflow\n");
            i = -1;        
        }
        
        ptr++;
        if (ptr > irrx_stack_end)
            ptr = irrx_stack_start;

    }
    else if ((irrx_get_time_elapsed() >= IRRX_TIMEOUT) && (i>0)){
        rawcode.length = i;
        irrx_handle_raw_code(rawcode);
        i = -1;                        
    }
}

void irrx_handle_raw_code(ir_raw_code_t rawcode){
    if (rawcode.length>6) {
        //ir_print_raw_code(rawcode);
        irrx_decode_space_encoded(rawcode);
    }

}

bool irrx_echo_busy = false;
ir_raw_code_t irrx_echo_rawcode;
uint32_t irrx_echo_timestamp;

void ir_echo_rawcode_init(ir_raw_code_t _rawcode){
    if(!irrx_echo_busy) {
        irrx_echo_busy = true;
        irrx_echo_rawcode = _rawcode;
        irrx_echo_timestamp = join16in32 (IC2TMR, IC1TMR);
    }
}

void ir_echo_rawcode_task(){
    if((irrx_get_time_elapsed_since(irrx_echo_timestamp) > IR_ECHO_DELAY) & irrx_echo_busy) {
        irrx_echo_busy = false;
        printf("Echo code %u\n", irrx_echo_rawcode.length);
        irtx_send_raw_code(irrx_echo_rawcode);
    }    
}
