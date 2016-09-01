/* 
 * File:   HardwareProfile.h
 * Author: philippe
 *
 * Created on February 20, 2016, 4:39 PM
 */

#ifndef HARDWAREPROFILE_H
#define	HARDWAREPROFILE_H

#define ENC__PIC24FJ__

#define ENC_CS_TRIS TRISBbits.TRISB0
#define ENC_CS_IO LATBbits.LATB0
#define ENC_SPISTAT SPI1STATL
#define ENC_SPISTATbits SPI1STATLbits
#define ENC_SPICON1bits SPI1CON1bits
#define ENC_SSPBUF SPI1BUFL
#define ENC_SPIBRGL SPI1BRGL
#define ENC_SPIBRGH SPI1BRGH

#define ENC_SPISTATL SPI1STATL
#define ENC_SPISTATH SPI1STATH
#define ENC_SPICON1L SPI1CON1L
#define ENC_SPICON1H SPI1CON1H
#define ENC_SPICON2 SPI1CON2L

#define PTR_BASE WORD
#define TCP_ETH_RAM_SIZE 5000

#include "tcpip_config.h"

#endif	/* HARDWAREPROFILE_H */

