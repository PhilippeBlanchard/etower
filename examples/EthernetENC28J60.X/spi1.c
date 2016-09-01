#include <xc.h>
#include "spi1.h"

void enc28j60_send( uint8_t addr, uint8_t data)
{
    uint16_t tmp;
    SPI1BUFL = ((addr+64)<<8)+data;
    while ( SPI1STATLbits.SPIRBE == true){}
    tmp = SPI1BUFL; // Must be done to empty buffer
}

uint8_t enc28j60_receive( uint8_t addr)
{
    SPI1BUFL = ((uint16_t)addr)<<8;
    while ( SPI1STATLbits.SPIRBE == true){}
    return (uint8_t) SPI1BUFL;
}

