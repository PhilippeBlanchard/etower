#include <stdbool.h>

#include "usb.h"
#include "configbits.h"
#include "hardware.h"
#include "usb_fonctions.h"

void heartBeat(void);

void main(void) {
	hwPinConfiguration();
	USBDeviceInit();

	usbPrint("Ready...",8);

	while(1){
     heartBeat();
     USBDeviceTasks();
		 usbRx();
		 usbTx();
	}
}

void heartBeat(void) {
    static uint16_t heartBeat; 

    heartBeat++;
    if (heartBeat > 2000) {
        heartBeat = 0;
        mLED_1_Toggle();
    }
}

//Entry level
size_t managerLevel1(uint8_t *request, uint8_t *response) {
	uint8_t *parameter;
	uint8_t *next;

	uint8_t address;
	uint8_t tmp[40];
	uint8_t i,v;
	uint16_t j;

	parameter = cutRequest(request, &next);
	
	if (parameter[0] == '\0') { // return if empty command
		return 0; 
	}
	else if (strcmp("status", parameter) == 0) {
		return catResponse(response, "Running usb2i2c\n"); 
	}
	else if (strcmp("led", parameter) == 0) {
		mLED_2_Toggle();
		return 0; 
	}

	return catResponse(response, "Command not reconized\n"); 	
}

bool USER_USB_CALLBACK_EVENT_HANDLER(USB_EVENT event, void *pdata, uint16_t size)
{
    switch(event)
    {
        case EVENT_TRANSFER:
            break;
        case EVENT_SOF:
            break;
        case EVENT_SUSPEND:
            break;
        case EVENT_RESUME:
            break;
        case EVENT_CONFIGURED:
            USBEnableEndpoint(USBGEN_EP_NUM,USB_OUT_ENABLED|USB_IN_ENABLED|USB_HANDSHAKE_ENABLED|USB_DISALLOW_SETUP);
            break;
        case EVENT_SET_DESCRIPTOR:
            break;
        case EVENT_EP0_REQUEST:
            break;
        case EVENT_BUS_ERROR:
            break;
        case EVENT_TRANSFER_TERMINATED:
            break;
        default:
            break;
    }
    return true;
}
