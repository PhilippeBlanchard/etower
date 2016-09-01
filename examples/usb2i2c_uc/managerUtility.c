#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#include "managerUtility.h"

uint8_t* cutRequest(uint8_t *request, uint8_t **next) {
	uint8_t *head;
	
	while (*request <= ' ' && *request != '\0') {
		request++;
	}
	
	head = request;

	while (*request > ' ' && *request != '\0') {
		request++;
	}

	if (*request == '\0') {
		*next = request;
	} else {
		*request = '\0';
		*next = request + 1;		
	}
	
	return head;
}

size_t catResponse(uint8_t *response, uint8_t *newString) {
	size_t responseLength;
	size_t newStringLength;

	responseLength = strlen(response);
	newStringLength = strlen(newString);
	
	if (newStringLength <= (RESPONSE_MAX_LENGTH-responseLength)) {
		strcat(response, newString);
		return responseLength+newStringLength;
	}
	
	return responseLength;
}

