#ifndef _ir_h
#define _ir_h

#ifdef __ir_c_
//#define __debug__
#include "debug.h"
#endif

#include <stdint.h>
#include <stdio.h>

#define MAX_RAW_LENGTH 100

typedef struct {
    uint8_t length;
    uint32_t code[MAX_RAW_LENGTH];
} ir_raw_code_t;


void ir_print_raw_code (ir_raw_code_t rawcode);

#endif // _ir_h