/* 
 * File:   bootloader.h
 * Author: philippe
 *
 * Created on May 2, 2016, 11:39 PM
 */

#ifndef BOOTLOADER_H
#define	BOOTLOADER_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <xc.h>    


typedef struct bl_api
{
    uint8_t (*getsUSBUSART)(uint8_t *buffer, uint8_t len);
    
    void (*putUSBUSART)(uint8_t *data, uint8_t  length);
    void (*putsUSBUSART)(char *data);
    void (*putrsUSBUSART)(const const char *data);
    void (*CDCTasks)(void);
    bool (*USBUSARTIsTxTrfReady)(void);
    
} bl_api_t;
    
#define GUEST_MEMORY_START 0x004000
#define GUEST_MEMORY_END   0x153FFF    

typedef uint32_t instruction_row[64];

void bl_init_api();
uint32_t bl_read_memory(uint32_t address);
void bl_write_memory(uint32_t address, uint32_t data);
void bl_write_chunk(uint32_t address, uint32_t data[64]);
void bl_erase (uint32_t address);

#ifdef	__cplusplus
}
#endif

#endif	/* BOOTLOADER_H */

