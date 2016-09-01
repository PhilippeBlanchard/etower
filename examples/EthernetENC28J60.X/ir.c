#define __ir_c_

#include "ir.h"

void ir_print_raw_code (ir_raw_code_t rawcode) {
    DEBUG_MACRO_PRINT_FUNTION

    uint8_t i;
    char on[10], off[10];
            
    printf("-------------------------\n");    
    printf("| Pos |   On   |  Off   |\n");
    printf("-------------------------\n");
    for(i=0; i<rawcode.length; i=i+2) {
        sprintf(on, "%6lu", rawcode.code[i]);
        if (i+1 < rawcode.length)
            sprintf(off, "%6lu", rawcode.code[i+1]);
        else
            sprintf(off, "      ");

        printf("| %3u | %s | %s |\n", i, on, off);        
    }
    printf("-------------------------\n");    
}