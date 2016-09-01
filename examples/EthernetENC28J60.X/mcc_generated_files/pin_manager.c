/**
  System Interrupts Generated Driver File 

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.c

  @Summary:
    This is the generated manager file for the MPLABï¿½ Code Configurator device.  This manager
    configures the pins direction, initial state, analog setting.
    The peripheral pin select, PPS, configuration is also handled by this manager.

  @Description:
    This source file provides implementations for MPLABï¿½ Code Configurator interrupts.
    Generation Information : 
        Product Revision  :  MPLABï¿½ Code Configurator - v2.10
        Device            :  PIC24FJ128GB202
        Version           :  1.02
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.23
        MPLAB             :  MPLAB X 2.26
*/
/*
Copyright (c) 2013 - 2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
*/

/**
    Section: Includes
*/
#include <xc.h>
#include "pin_manager.h"

/**
    void PIN_MANAGER_Initialize(void)
*/
void PIN_MANAGER_Initialize(void)
{
    /****************************************************************************
     * Setting the GPIO of PORTA
     ***************************************************************************/
    LATA = 0x00;
    TRISA = 0x00;
    /****************************************************************************
     * Setting the GPIO of PORTB
     ***************************************************************************/
    LATB = 0x00;
    TRISB = 0x277F;

    /****************************************************************************
     * Setting the Analog/Digital Configuration SFR
     ***************************************************************************/
    //ANSA = 0x0F;
    //ANSB = 0x024F;
    ANSA = 0;
    ANSB = 0;

    // Timer
    T2CONbits.T32 = 1;
    T2CONbits.TCKPS = 1;
    T2CONbits.TON = 1;

    //Serial Port
    U1BRG = 416; // 9600
    // U1BRG = 207; // 19200
    // U1BRG = 68; // 57600

    U1MODEbits.BRGH = 1;
    U1MODEbits.UARTEN = 1;
    U1STAbits.UTXEN = 1;
    U1STAbits.URXEN = 1;
    
    /****************************************************************************
     * Set the PPS
     ***************************************************************************/
    __builtin_write_OSCCONL(OSCCON & 0xbf); // unlock PPS

    //UART 1
    RPOR3bits.RP7R = 3;    //UART1:TX
    RPINR18bits.U1RXR = 8; //UART1:RX
    
    //SPI 1
    RPOR0bits.RP1R = 8;    //SPI1:SCK
    RPOR1bits.RP2R = 7;    //SPI1:SDO
    RPINR20bits.SDI1R = 3; //SPI1:SDI
    //SPI1:SS -> in code

    //PWM
    //RPOR3bits.RP7R = 13;  // à réassigner
    RPOR4bits.RP9R = 13;
    OC1CON2bits.SYNCSEL = 0x1F;
    OC1CON1bits.OCTSEL = 7;
    OC1CON1bits.OCM = 6;
    OC1R = 0;
    
    //Input Capture
    RPINR7bits.IC1R = 4;
    IC2CON2bits.IC32 = 1;
    IC1CON2bits.IC32 = 1;
    IC2CON2bits.SYNCSEL = 0;
    IC1CON2bits.SYNCSEL = 0;
    IC2CON1bits.ICTSEL = 1;
    IC1CON1bits.ICTSEL = 1;
    IC2CON2bits.ICTRIG = 0;
    IC1CON1bits.ICM = 1;
    IC2CON1bits.ICM = 1;
    IEC0bits.IC1IE = 1;

    
    __builtin_write_OSCCONL(OSCCON | 0x40); // lock   PPS
}

