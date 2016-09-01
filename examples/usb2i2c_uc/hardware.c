#include "hardware.h"

void hwPinConfiguration() {

	ANSB = 0; //Digital for port B
	TRISAbits.TRISA2 = 0;
	TRISAbits.TRISA3 = 0;  

	U1BRG = 416;
	U1MODEbits.BRGH = 1;
	U1MODEbits.UARTEN = 1;
	U1STAbits.UTXEN = 1;

	TRISBbits.TRISB3 = 0;

	__builtin_write_OSCCONL(OSCCON & 0xbf); // unlock PPS
  RPOR4bits.RP8R = 3;    //UART1:TX
	__builtin_write_OSCCONL(OSCCON | 0x40); // lock	PPS


}

