/* 
 * File:   irrx.h
 * Author: philippe
 *
 * Created on March 24, 2016, 8:34 AM
 */

#ifndef IRRX_H
#define	IRRX_H

#include <xc.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "ir.h"
#include "irtx.h"


#define IRRX_DEBUG_PRINT_RX

#define IR_FIFO_LENGTH 256 // Must bu power of 2
#define IR_FIFO_MASK (IR_FIFO_LENGTH-1u) 
#define ItemPerLine 16

#define IR_ECHO_DELAY 5000000u
#define IRRX_TIMEOUT   100000u
#define IRRX_GAP        10000u
#define IRRX_HEADER      3000u
#define IRRX_ONE         1200u
#define IRRX_ZERO         400u

#define irrx_input_is_up() (!PORTBbits.RB4)
#define irrx_input_is_down() PORTBbits.RB4
#define is_even(mdata) (!(mdata & 1))
#define is_odd(mdata) (mdata & 1)
#define join16in32(high, low) (((uint32_t) high << 16) + low)

void irrx_init(void);
void irrx_task (void);
void irrx_int(void);
void irrx_append_data_stack(uint32_t mydata);
uint32_t irrx_get_duration (void);
uint32_t irrx_get_time_elapsed();
uint32_t irrx_get_time_elapsed_since (uint32_t timestamp);

void irrx_print_fifo (void);
void irrx_reset_data_text(void);
void irrx_flush_data_text(void);
void irrx_append_data_text(uint32_t mydata);
void irrx_flush_data_code(uint32_t result, uint8_t codelength);

void irrx_set_verbose(uint8_t level);
void irrx_set_echo(bool state);
void irrx_set_sync(bool state);

void ir_sync_rx_tx(void);
void irrx_decode (void);
void irrx_echo (void);
void irrx_extract_raw_code();
void irrx_handle_raw_code(ir_raw_code_t rawcode);
void irrx_decode_space_encoded (ir_raw_code_t rawcode);

void ir_echo_rawcode_init(ir_raw_code_t _rawcode);
void ir_echo_rawcode_task();

#ifdef IRRX_C

#endif

#endif	/* IRRX_H */

