#ifndef _MANAGERUTILITY_H
#define _MANAGERUTILITY_H

#define RESPONSE_MAX_LENGTH 256-1 // Condider terminal uint8_tacter '\0'

uint8_t* cutRequest(uint8_t *request, uint8_t **next);
size_t catResponse(uint8_t *response, uint8_t *newString);

#endif
