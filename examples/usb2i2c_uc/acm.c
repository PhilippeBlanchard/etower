#include <stdio.h>
#include "acm.h"
#include <string.h>

char acmRxBuffer[acmRxBufferSize];

void acmBufferCharacter(uint8_t c) {
	static uint16_t offset;

	switch(c) {
		case '\b':
			if (offset)
			offset--;
			break;

		case '\r':
			acmRxBuffer[offset] = c;
			offset++;
			acmRxBuffer[offset] = '\0';
			acmExecuteRequest(acmRxBuffer);
			offset = 0;
			acmRxBuffer[0] = '\0';
			break;

		default:
			acmRxBuffer[offset] = c;
			offset++;
	}
 
	if ( offset >= acmRxBufferSize ){
		offset = 0;
		acmRxBuffer[0] = '\0';
		return;
	}
}


void acmExecuteRequest(uint8_t *request) {
	uint8_t responseLength;
	uint8_t response[256];
	static uint16_t counter = 0;

	response[0] = '\0';
	responseLength = managerLevel1(request, response);
	acmPrintString(response);

	counter++;	
	response[0] = '\0';
	responseLength = sprintf(response, "<%u> ", counter);
	acmPrintString(response);
}

void acmPrintString(uint8_t *mystring) {
	uint8_t length;
	length = strlen(mystring);
	usbPrint(mystring, length);

}
