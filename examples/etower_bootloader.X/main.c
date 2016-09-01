#include <xc.h>
#include <stdint.h>
#include <stdio.h>


#include "configbits.h"
#include "ledmacros.h"
#include "terminal.h"
#include "bootloader.h"
#include "system.h"
#include "main.h"

uint8_t timekeeper;

int main(void) {  
    init_device();
    USBDeviceInit();
    bl_init_api();

    timekeeper = 0;
    T1CONbits.TCKPS = 3;
    T1CONbits.TON = 1;
    
    while(1){
        heartBeat();
        CDCTasks();
        TerminalTasks();
        if (timekeeper > 3) {
            //asm("CALL 0x4200"); 
            timekeeper = 0;        
        }
    };
    return(0);
}

void init_device(void) {
    // Led configuration
    TRISAbits.TRISA2 = 0;
    TRISAbits.TRISA3 = 0;  
}

#define TIME_TRIGGER 62500/10
void heartBeat(void) {
    uint16_t delta;
    
    if (IFS0bits.T1IF) {
        //Add some stuff with PR1 to fix time
        IFS0bits.T1IF = 0;
        timekeeper++;

        PR1 = TIME_TRIGGER;
        
        //printf("%u\n", PR1);
        mLED_1_Toggle();
    }
}
 
void CDCTasks(void) {
    USBDeviceTasks();
    CDCTxService();
}

void TerminalTasks(void) {
    //uint8_t dummy, y;    
    uint8_t count, i, string[64];

    count = getsUSBUSART(string,64);
    for (i=0; i < count; i++) {
        timekeeper = 0;
        switch(string[i]) {
            case 0x0A:
                break;
            case 0x0D:
                terminal_flush();
                break;
            default:
                //putchar(string[i]);
                terminal_serialize(string[i]);     
        }
    }
    
}

bool fUSBUSARTIsTxTrfReady() {
    return cdc_trf_state == CDC_TX_READY;
}

bool USER_USB_CALLBACK_EVENT_HANDLER(USB_EVENT event, void *pdata, uint16_t size)
{
    //printf("USER_USB_CALLBACK_EVENT_HANDLER\n");
    switch(event)
    {
        case EVENT_TRANSFER:
            //Add application specific callback task or callback function here if desired.
            break;
        case EVENT_SOF:
            //USBCB_SOF_Handler();
            break;
        case EVENT_SUSPEND:
            //USBCBSuspend();
            break;
        case EVENT_RESUME:
            //USBCBWakeFromSuspend();
            break;
        case EVENT_CONFIGURED:
            CDCInitEP();
            break;
        //case EVENT_SET_DESCRIPTOR:
            //USBCBStdSetDscHandler();
            break;
        case EVENT_EP0_REQUEST:
            USBCheckCDCRequest();
            break;
        case EVENT_BUS_ERROR:
            //USBCBErrorHandler();
            break;
       // case EVENT_TRANSFER_TERMINATED:
            break;
        default:
            break;
    }
    return true;
}

#define STDIN   0
#define STDOUT  1
#define STDERR  2

int __attribute__((__section__(".libc")))
write(int handle, void * buffer, unsigned int len)
{
    int i = 0;
    switch (handle)
    {
        case STDOUT:
        case STDERR:    while (i < len)
                            mon_putc(((char*)buffer)[i++]);
                        break;
    }
    return (len);  // number of characters written
}

 void mon_putc (char c)
 {
    // Send data over USB
    putUSBUSART((uint8_t *) &c, 1);
    while ( !fUSBUSARTIsTxTrfReady() ) {
        USBDeviceTasks();        
        CDCTxService();
    }
}
