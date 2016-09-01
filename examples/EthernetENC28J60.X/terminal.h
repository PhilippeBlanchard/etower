#include <stdio.h>
#include <stdint.h>
#include "system_config.h"
#include "irrx.h"

#ifdef __terminal_c_
//#define __debug__
#include "debug.h"
#endif //__terminal_c_

// Terminal core management
void terminal_exec();
void terminal_extract_string(void);

// Serial management
void terminal_serialize(char c);
void terminal_flush();
void terminal_reset_line(void);

// LED management
void terminal_level2_led(void);

// IRRX management
void terminal_level2_irrx();  
void terminal_level3_irrx_verbose();
void terminal_level3_irrx_set_sync();

// IRTX management
void terminal_level2_irtx();
void terminal_level3_irtx_send_raw();
void terminal_level3_irtx_set_frequency();


