/* 
 * File:   usbFonctions.h
 * Author: philippe
 *
 * Created on September 1, 2014, 9:53 AM
 */

#ifndef USBFONCTIONS_H
#define	USBFONCTIONS_H

#include <stdlib.h>
#include <stdio.h>

#include "usb/usb.h"
#include "usb/usb_device.h"

typedef struct usbPacket
{
    union {
        uint8_t  _byte[USBGEN_EP_SIZE];  //For byte access
        struct
        {
            uint8_t cmd;
            uint8_t data;
        };
        struct
        {
            uint8_t :8;
            uint16_t irLength[6];
        };
    };
} usbPacket;

typedef struct userPacket
{
    union {
        uint8_t cmd;
        struct {
            uint8_t array[32];  //For byte access
            uint8_t length;
        };
        struct {
            unsigned :8;
            uint16_t wordArray[16];
        };
    };
    struct {
        unsigned :8;
        uint8_t wlength;
    };
} userPacket;

typedef struct stackedPacket
{
    uint8_t size;
    usbPacket packet;
} stackedPacket;

#define USB_Packet_Size pBDTEntryOut[USBGEN_EP_NUM]->CNT
#define USB_In_Stack_Length 32

#define mUSBPrint(string) usbPrint(string, sizeof(string))

#define mUSBsprintf(_mystring, ...) \
    length = sprintf(myString, _mystring, __VA_ARGS__); \
    usbPrint(myString, length);

#ifndef __USB_FONCTIONS_C 
extern char myString[30];
extern uint8_t length;
#endif

void copyArray(uint8_t* fromArray, uint8_t fromOffset, uint8_t* toArray, uint8_t toOffset, uint8_t count);
void usbRx(void);
void stackUSBPacket(const usbPacket pkt, uint8_t length);
void usbTx(void);
void usbPrint(char* myString, uint8_t count);

//extern void userHandlePacket(userPacket *pkt);

#endif	/* USBFONCTIONS_H */

