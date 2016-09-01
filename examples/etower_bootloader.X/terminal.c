#define __terminal_c_

#include "terminal.h"

char terminal_line[1024]; // FIX ME! Try to get rid of this global variable (malloc?)
char *terminal_current_string, *terminal_next_string;
uint16_t terminal_position;
uint16_t terminal_count;

 
//---------------------------------------------------------
// Terminal core management
//---------------------------------------------------------
void terminal_exec() {
       
    terminal_extract_string();
    
    if(strlen(terminal_current_string) == 0) {
    } 
    else if (strcmp("status", terminal_current_string) == 0) {
        printf("eTower (tm) - Running bootloader\n");         
    }
    else if (strcmp("led", terminal_current_string) == 0) {
        terminal_level2_led();         
    }
    else if (strcmp("bootloader", terminal_current_string) == 0) {
        terminal_level2_bootloader();         
    }
    else if (strcmp("cat", terminal_current_string) == 0) {
        putrsUSBUSART("Hello world!\n");         
    }
    else if (strcmp("run", terminal_current_string) == 0) {
        asm("CALL 0x4200");         
    }
    else {
        printf("Command unknown: %s\n", terminal_current_string);                 
    }
    
}

bool terminal_extract_string(void) {
    DEBUG_MACRO_PRINT_FUNTION

    if (*terminal_next_string == '\0')
        return false;

    terminal_current_string = terminal_next_string;
    terminal_next_string = strchr(terminal_current_string, ' ');
    if (terminal_next_string) {
        *terminal_next_string = '\0';
        terminal_next_string++;
    }
    return true;
}

//---------------------------------------------------------
// Serial management
//---------------------------------------------------------
void terminal_serialize(char c) {
    
    if ( terminal_position >= 1023 ){
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
// Bootloader command
//---------------------------------------------------------
void terminal_level2_bootloader() {
    
    terminal_extract_string();  
    if(strlen(terminal_current_string) == 0) {
        printf("Error: Bootloader: no action specified\n");
        return;
    } 

    else if (strcmp("read", terminal_current_string) == 0) {
        terminal_level3_bootloader_read();
    }
    else if (strcmp("read_chunk", terminal_current_string) == 0) {
        terminal_level3_bootloader_read_chunk();
    }
    else if (strcmp("find_chunk_end", terminal_current_string) == 0) {
        terminal_level3_bootloader_find_chunk_end();
    }
    else if (strcmp("write", terminal_current_string) == 0) {
        terminal_level3_bootloader_write();
    }
    else if (strcmp("write_chunk", terminal_current_string) == 0) {
        terminal_level3_bootloader_write_chunk();
    }
    else if (strcmp("erase", terminal_current_string) == 0) {
        terminal_level3_bootloader_erase();
    }
    else {
        printf("Error: Bootloader: Invalid action %s\n", terminal_current_string);                 
    }    
}

void terminal_level3_bootloader_read() {
    uint32_t data;
    uint32_t address;
    
    terminal_extract_string();  
    if(strlen(terminal_current_string) == 0) {
        printf("Error: Bootloader: No address specified\n");
        return;
    } 
    address = strtol(terminal_current_string,0,16);
    
    data = bl_read_memory(address);
    
    printf("Read address 0x%04lx -> 0x%06lx \n", address, data);
    
}

void terminal_level3_bootloader_read_chunk() {
    uint32_t data;
    uint32_t address;
    
    terminal_extract_string();  
    if(strlen(terminal_current_string) == 0) {
        printf("Error: Bootloader: No address specified\n");
        return;
    } 
    address = strtol(terminal_current_string,0,16);
    
    while ((data = bl_read_memory(address)) != 0xffffff) {
        printf("Read address 0x%04lx -> 0x%06lx \n", address, data);
        address += 2;
    }
}

void terminal_level3_bootloader_find_chunk_end() {
    uint32_t data;
    uint32_t start, end;
    
    terminal_extract_string();  
    if(strlen(terminal_current_string) == 0) {
        printf("Error: Bootloader: No address specified\n");
        return;
    } 
    start = strtol(terminal_current_string,0,16);
    end = start;
    while ((data = bl_read_memory(end)) != 0xffffff) {
        end += 2;
        if (end >= 0x15ff)
            break;
    }
    
    if (start != end)
        printf("Chunk is from 0x%06lx to 0x%06lx\n", start, end);
    else
        printf("No chunk at 0x%04lx\n", start);
}

void terminal_level3_bootloader_write() {
    uint32_t data;
    uint32_t address;
    
    terminal_extract_string();  
    if(strlen(terminal_current_string) == 0) {
        printf("Error: Bootloader: No address specified\n");
        return;
    } 
    address = strtol(terminal_current_string,0,16);

    terminal_extract_string();  
    if(strlen(terminal_current_string) == 0) {
        printf("Error: Bootloader: No data specified\n");
        return;
    } 
    data = strtol(terminal_current_string,0,16);

    bl_write_memory(address, data);
    
    //printf("Write address 0x%04lx -> 0x%06lx \n", address, data);
    
}

void terminal_level3_bootloader_write_chunk() {
    uint8_t i;
    uint32_t address;
    uint32_t data[64];

    if(terminal_extract_string() == false) {
        printf("Error: Bootloader: No address specified\n");
        return;
    } 

    address = strtol(terminal_current_string,0,16);
    
    for (i=0; i<64; i++) {
        if(terminal_extract_string() == false) {
            printf("Error: Bootloader: Not enough data\n");
            return;
        } 
        //printf("0x%06lx: %s\n", address + 2*i, terminal_current_string);
        data[i] = strtol(terminal_current_string,0,16);
    }
    bl_write_chunk(address, data);
    printf("0x%08lx done\n", address);

}

void terminal_level3_bootloader_erase() {
    uint32_t address;
    
    terminal_extract_string();  
    if(strlen(terminal_current_string) == 0) {
        printf("Error: Bootloader: No address specified\n");
        return;
    } 
    address = strtol(terminal_current_string,0,16);

    bl_erase(address);
    
}

