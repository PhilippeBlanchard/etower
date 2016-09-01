// USB Abstract Control Model

#ifndef _USERCDC_H
#define _USERCDC_H

#include <stdint.h>
#include "hardware.h"
#include "usb_fonctions.h"

#define acmRxBufferSize 256

void acmBufferCharacter(uint8_t c);
void acmExecuteRequest(uint8_t *request);
void acmPrintString(uint8_t *mystring);

#endif
