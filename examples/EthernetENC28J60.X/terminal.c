#define __terminal_c_

#include "terminal.h"

char terminal_line[255];
char *terminal_current_string, *terminal_next_string;
uint8_t terminal_position;
uint16_t terminal_count;

//---------------------------------------------------------
// Terminal core management
//---------------------------------------------------------
void terminal_exec() {
    
    terminal_extract_string();
    
    if(strlen(terminal_current_string) == 0) {
    } 
    else if (strcmp("status", terminal_current_string) == 0) {
        printf("Running\n");         
    }
    else if (strcmp("led", terminal_current_string) == 0) {
        terminal_level2_led();         
    }
    else if (strcmp("irrx", terminal_current_string) == 0) {
        terminal_level2_irrx();         
    }
    else if (strcmp("irtx", terminal_current_string) == 0) {
        terminal_level2_irtx();         
    }           
    else {
        printf("Command unknown: %s\n", terminal_current_string);                 
    }
    
}

void terminal_extract_string(void) {
    DEBUG_MACRO_PRINT_FUNTION
    
    terminal_current_string = terminal_next_string;
    terminal_next_string = strchr(terminal_current_string, ' ');
    if (terminal_next_string) {
        *terminal_next_string = '\0';
        terminal_next_string++;
    }
    if (*terminal_next_string == '\0')
        terminal_next_string = NULL;    
}

//---------------------------------------------------------
// Serial management
//---------------------------------------------------------
void terminal_serialize(char c) {
    
    if ( terminal_position >= 254 ){
        return;
    }
    else if (c == 0x08) {
        if (terminal_position > 0)
            terminal_position--;
    }
    else if (c == ' ') {
        if (terminal_position > 0)
            if (terminal_line[terminal_position-1] != ' ') { 
                terminal_line[terminal_position] = c;
                terminal_position++;
            }
    }    
    else {
    terminal_line[terminal_position] = c;
    terminal_position++;
    }
}

void terminal_flush() {
    terminal_line[terminal_position] = '\0';
    //putchar('\n');
    terminal_exec();
    terminal_reset_line();
}

void terminal_reset_line(void) {
    terminal_count++;
    terminal_position = 0;
    memset(terminal_line, '\0', sizeof(terminal_line));
    terminal_next_string = terminal_line;
    printf("<%u> ",terminal_count);
}


//---------------------------------------------------------
// LED management
//---------------------------------------------------------
void terminal_level2_led() {
    
    terminal_extract_string();  
    if(strlen(terminal_current_string) == 0) {
        printf("Error: No LED specified\n");                         
    } 
    //else if (strcmp("1", terminal_current_string) == 0) {
    //}
    else if (strcmp("2", terminal_current_string) == 0) {
    }
    else {
        printf("Error: No LED %s\n", terminal_current_string);                 
    }    

    terminal_extract_string();  
    if(strlen(terminal_current_string) == 0) {
        printf("Error: LED - need to specify an action\n");                         
    } 
    else if (strcmp("on", terminal_current_string) == 0) {
        mLED_2_On();
    }
    else if (strcmp("off", terminal_current_string) == 0) {
        mLED_2_Off();
    }
    else if (strcmp("toggle", terminal_current_string) == 0) {
        mLED_2_Toggle();
    }    
    else {
        printf("Error: LED - Action %s invalid\n", terminal_current_string);                 
    }    
}


//---------------------------------------------------------
// IRRX management
//---------------------------------------------------------
void terminal_level2_irrx() {
    terminal_extract_string();  
    if(strlen(terminal_current_string) == 0) {
        printf("Error: IRRX - need to specify an action\n");                         
    } 
    else if (strcmp("verbose", terminal_current_string) == 0) {
        terminal_level3_irrx_verbose();
    }
    else if (strcmp("record_once", terminal_current_string) == 0) {
        printf("Record once\n");
    }
    else if (strcmp("set_sync", terminal_current_string) == 0) {
        terminal_level3_irrx_set_sync();
    }    
    else {
        printf("Error: IRRX - Action %s invalid\n", terminal_current_string);                 
    }        
}

void terminal_level3_irrx_verbose(){
    DEBUG_MACRO_PRINT_FUNTION
            
    uint8_t level;
    
    terminal_extract_string();  
    if(strlen(terminal_current_string) == 0) {
        printf("Error: (IRRX|Verbose) Need to specify the level\n");                         
    } 
    else {
        sscanf(terminal_current_string, "%u", (unsigned int*) &level);
        irrx_set_verbose(level);
    }        
}

void terminal_level3_irrx_set_sync() {
    DEBUG_MACRO_PRINT_FUNTION
    
    terminal_extract_string();  
    if(strlen(terminal_current_string) == 0) {
        printf("Error: (IRRX|set_sync) Need to specify on/off\n");                         
    } 
    else if (strcmp("on", terminal_current_string) == 0) {
        irrx_set_sync(true);
    }
    else if (strcmp("off", terminal_current_string) == 0) {
        irrx_set_sync(false);
    }
    else {
        printf("Error: IRRX/sync must be on or off\n");                 
    }        
}


//---------------------------------------------------------
// IRTX management
//---------------------------------------------------------
void terminal_level2_irtx() {
    terminal_extract_string();  
    if(strlen(terminal_current_string) == 0) {
        printf("Error: irtx - need to specify an action\n");                         
    } 
    else if (strcmp("send_raw", terminal_current_string) == 0) {
        terminal_level3_irtx_send_raw();
    }
    else if (strcmp("repeat_raw", terminal_current_string) == 0) {
        irtx_send_raw_code(irtx_raw_code);
    }
    else if (strcmp("set_frequency", terminal_current_string) == 0) {
        terminal_level3_irtx_set_frequency();
    }
    else {
        printf("Error: irrx - Action %s invalid\n", terminal_current_string);                 
    }        
}

void terminal_level3_irtx_set_frequency() {
    DEBUG_MACRO_PRINT_FUNTION
    
    short unsigned int frequency, duty;
    
    terminal_extract_string();  
    if(strlen(terminal_current_string) == 0) {
        printf("[Error] irtx set_frequency: Need to specify frequency\n");  
        return;
    } 
    else {
        sscanf(terminal_current_string, "%hu", &frequency);
    }        

    terminal_extract_string();  
    if(strlen(terminal_current_string) == 0) {
        printf("[Error] irtx set_frequency: Need to specify duty\n");
        return;
    } 
    else {
        sscanf(terminal_current_string, "%hu", &duty);
    }        
    
    printf("Set frequency to %ukhz and duty to %u%%\n", frequency, duty);
    irtx_set_frequency_duty(frequency, duty);
}

void terminal_level3_irtx_send_raw() {
    DEBUG_MACRO_PRINT_FUNTION
    
    uint8_t i;
    
    ir_raw_code_t rawcode;
    uint32_t delay;
    
    i=0;
    terminal_extract_string();     
    while (terminal_current_string != NULL) {
        if(strlen(terminal_current_string) > 0) {
            sscanf(terminal_current_string, "%lu", &delay);
            //printf("%s i=%u %lu\n", __func__, i, delay);
            rawcode.code[i] = delay;
            i++;
            terminal_extract_string();
        }
    }
    rawcode.length = i;

    //ir_print_raw_code(rawcode);
    irtx_send_raw_code(rawcode);
}

