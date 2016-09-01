#ifndef _SPI1_H
#define _SPI1_H

#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

void SPI1_Initialize (void);

void enc28j60_send( uint8_t addr, uint8_t data);
uint8_t enc28j60_receive( uint8_t addr);


#endif //_SPI1_H
    
/*******************************************************************************
 End of File
*/
