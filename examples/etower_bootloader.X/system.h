/******************************************************************************/
/* System Level #define Macros                                                */
/******************************************************************************/

/* TODO Define system operating frequency */

/* Microcontroller MIPs (FCY) */
//#define SYS_FREQ        48000000L
//#define FCY             SYS_FREQ/4

/******************************************************************************/
/* System Function Prototypes                                                 */
/******************************************************************************/

/* Custom oscillator configuration funtions, reset source evaluation
functions, and other non-peripheral microcontroller initialization functions
go here. */

//void ConfigureOscillator(void); /* Handles clock switching/osc initialization */
#ifndef SYSTEM_H
#define SYSTEM_H

#define BYTE unsigned char

#include "usb_config.h"
#include <usb_device.h>
#include <usb_device_cdc.h>
#include <xc.h>

#endif