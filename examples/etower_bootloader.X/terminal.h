#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "ledmacros.h"
#include "bootloader.h"
#include <usb_device_cdc.h>
#ifdef __terminal_c_
//#define __debug__
#include "debug.h"
#endif //__terminal_c_

// Terminal core management
void terminal_exec();
bool terminal_extract_string(void);

// Serial management
void terminal_serialize(char c);
void terminal_flush();
void terminal_reset_line(void);

// LED management
void terminal_level2_led(void);

// Bootloader
void terminal_level2_bootloader();
void terminal_level3_bootloader_read();
void terminal_level3_bootloader_read_chunk();
void terminal_level3_bootloader_find_chunk_end();
void terminal_level3_bootloader_write();
void terminal_level3_bootloader_write_chunk();
void terminal_level3_bootloader_erase();