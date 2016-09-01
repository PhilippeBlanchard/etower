/* 
 * File:   irrx.h
 * Author: philippe
 *
 * Created on March 24, 2016, 8:34 AM
 */

#ifndef IRRX_H
#define	IRRX_H

#include <stdint.h>


#define IR_FIFO_LENGTH 256 // Must bu power of 2
#define IR_FIFO_MASK (IR_FIFO_LENGTH-1u) 
#define ItemPerLine 16

#define IRRX_TIMEOUT 100000u
#define IRRX_GAP 10000u
#define IRRX_HEADER 3000u
#define IRRX_ONE 1200u
#define IRRX_ZERO 200u

#define irrx_input_is_up() (!PORTBbits.RB4)
#define irrx_input_is_down() PORTBbits.RB4
#define is_even(mdata) (!(mdata & 1))
#define is_odd(mdata) (mdata & 1)
#define join16in32(high, low) (((uint32_t) high << 16) + low)

void irrx_print_fifo (void);
uint32_t irrx_get_duration (void);
void irrx_task (void);
void irrx_init(void);
void irrx_reset_data_text(void);
void irrx_flush_data_text(void);
void irrx_append_data_text(uint32_t mydata);
void irrx_append_data_stack(uint32_t mydata);
void ir_sync_rx_tx(void);
void irrx_decode (void);
void irrx_flush_data_code(uint32_t result, uint8_t codelength);

#ifdef IRRX_C

#endif

#endif	/* IRRX_H */

