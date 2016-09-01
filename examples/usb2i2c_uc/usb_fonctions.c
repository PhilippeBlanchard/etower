#define __USB_FONCTIONS_C

#include "usb_fonctions.h"
#include "acm.h"

#define	min(a,b)	(((a) < (b)) ? (a) : (b))

char myString[30];
uint8_t length;

void usbRx() {
    static USB_HANDLE USBGenericOutHandle = NULL;
    static usbPacket usbOutPacket;
    static userPacket userBuffer;
		uint8_t i;

    if (USBGenericOutHandle ==  NULL)
        USBGenericOutHandle = USBRxOnePacket(USBGEN_EP_NUM,usbOutPacket._byte,USBGEN_EP_SIZE);
   
    if(!USBHandleBusy(USBGenericOutHandle) && pBDTEntryIn[USBGEN_EP_NUM] != 0)
    {
    	copyArray(usbOutPacket._byte,0,userBuffer.array,0,USB_Packet_Size);
      userBuffer.length = USB_Packet_Size;
      stackUSBPacket(usbOutPacket, USB_Packet_Size);
			
			for(i=0; i<USB_Packet_Size; i++) { 
				acmBufferCharacter(usbOutPacket._byte[i]);
			}
      USBGenericOutHandle = USBRxOnePacket(USBGEN_EP_NUM,usbOutPacket._byte,USBGEN_EP_SIZE);     
    }
}

stackedPacket USB_In_Stack[USB_In_Stack_Length];
uint8_t queueWriteOffset = 0;
uint8_t queueNextWriteOffset = 0;

void stackUSBPacket(const usbPacket pkt, uint8_t length) {
    uint8_t bkp;

    USB_In_Stack[queueWriteOffset].packet = pkt;
    USB_In_Stack[queueWriteOffset].size = length;
    bkp = queueWriteOffset;
    queueWriteOffset++;
    if (queueWriteOffset >= USB_In_Stack_Length)
        queueWriteOffset = 0;
    if (queueWriteOffset == queueNextWriteOffset)
        queueWriteOffset = bkp;
}

void usbTx(void)
{
    static usbPacket usbInPacket;
    static USB_HANDLE USBGenericInHandle = NULL;
    
    if (!USBHandleBusy(USBGenericInHandle) && pBDTEntryOut[USBGEN_EP_NUM] != 0) {
        if (queueNextWriteOffset != queueWriteOffset) {
            copyArray(USB_In_Stack[queueNextWriteOffset].packet._byte,0,usbInPacket._byte,0,USB_In_Stack[queueNextWriteOffset].size);
            USBGenericInHandle = USBTxOnePacket(USBGEN_EP_NUM, usbInPacket._byte, USB_In_Stack[queueNextWriteOffset].size);

            queueNextWriteOffset++;
            if (queueNextWriteOffset >= USB_In_Stack_Length)
            	queueNextWriteOffset = 0;

        } else {
            USBGenericInHandle = USBTxOnePacket(USBGEN_EP_NUM, usbInPacket._byte, 0);
				}
    }
}

void copyArray(uint8_t* fromArray, uint8_t fromOffset, uint8_t* toArray, uint8_t toOffset, uint8_t count) {
    uint8_t i;
    for (i=0; i<count; i++) {
        toArray[i+toOffset] = fromArray[i+fromOffset];
    }
}

void usbPrint(char* myString, uint8_t count){
    uint8_t length, offset;
    usbPacket pkt;

    offset = 0;
    while (offset < count) {
        length = min((count - offset), USBGEN_EP_SIZE);
        copyArray ((uint8_t *) myString, offset, pkt._byte, 0, length);
        offset += length;
        stackUSBPacket(pkt, length);
    }
}

