/* 
 * File:   EthernetENCJ28J60.c
 * Author: philippe
 *
 * Created on March 4, 2015, 6:13 PM
 */

#include <xc.h>
#include "confbits.h"
#include "system_config.h"
#include "tcpip_config.h"
#include "usb_config.h"
#include "irtx.h"
#include "irrx.h"
#include "terminal.h"

void heartBeat(void);

APP_CONFIG AppConfig;
MAC_ADDR broadcast;
uint8_t result;

//__attribute__ (( address(0x4200) )) 

int main(int argc, char** argv) {

    uint8_t dummy;
    
    AppConfig.MyIPAddr.Val = MY_DEFAULT_IP_ADDR_BYTE1 | MY_DEFAULT_IP_ADDR_BYTE2 << 8ul | MY_DEFAULT_IP_ADDR_BYTE3 << 16ul | MY_DEFAULT_IP_ADDR_BYTE4 << 24ul;
    AppConfig.MyMACAddr.v[0] = 0x02;
    AppConfig.MyMACAddr.v[1] = 0x03;
    AppConfig.MyMACAddr.v[2] = 0x04;
    AppConfig.MyMACAddr.v[3] = 0x05;
    AppConfig.MyMACAddr.v[4] = 0x06;
    AppConfig.MyMACAddr.v[5] = 0x02;
    AppConfig.Flags.bIsDHCPEnabled = true;

    // Device initialization
    USBDeviceInit();
    //TickInit();
    //StackInit();
    //eTowerTCPServerInit();
    //irtxInit();
    //irrx_init();    
    terminal_reset_line();

    // Print Ready messages
    PIN_MANAGER_Initialize();
    //mUSBPrint("Ready...\n");
    printf("Ready...\n");
    //eTowerTCPPrint("Ready...\n");    
    
    while(1){
        //USBDeviceTasks();
        //StackTask();
        //StackApplications();
        //eTowerTCPServer();
        heartBeat();
        //irrx_task();
        //usbRx();
        //usbTx();
        
        char y;
        if (U1STAbits.OERR){
            U1STAbits.OERR = 0;
            //while(U1STAbits.URXDA) {
            //    dummy = U1RXREG;
            //};            
        }
        dummy = U1STAbits.OERR;
        if (U1STAbits.URXDA) {
            y = U1RXREG;
            
            if (y == 0x0A) {
            } 
            else if (y == 0x0D) {
                terminal_flush();                
            } 
            else {
                //putchar(y);
                terminal_serialize(y);                
            }
        }
    }

    return (EXIT_SUCCESS);
}

void heartBeat(void) {
    static uint16_t heartBeat; 

    heartBeat++;
    if (heartBeat > 2000) {
        heartBeat = 0;
        mLED_1_Toggle();
    }
}

void userHandlePacket(userPacket *pkt) {
    switch(pkt->cmd) {
        case 0x00:
            mUSBPrint("Command 0x00\n");
            break;
        case 0x01:
            mLED_2_On();
            break;
        case 0x02:
            mLED_2_Off();
            break;
        case 0x08:
            irtxParameters = pkt->irtxParameters;
            printf("IR Code = %lx\n", irtxParameters.irCode);
            irtxSend();
            break;
    }
}

void __attribute__ ((__interrupt__, __auto_psv__)) _T3Interrupt(void) {
    intIrTx();
    IFS0bits.T3IF = 0;
    return;
}

void __attribute__ ((__interrupt__, __auto_psv__)) _IC1Interrupt(void) {
    irrx_int();
    IFS0bits.IC1IF = 0;
    return;
}


