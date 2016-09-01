#include "bootloader.h"
#include "main.h"
#include <usb_device_cdc.h>

bl_api_t bl_interface __attribute__((address(0x800)));

void bl_init_api() {
    bl_interface.CDCTasks = CDCTasks;
    bl_interface.getsUSBUSART = getsUSBUSART;
    bl_interface.putUSBUSART = putUSBUSART;
    bl_interface.putrsUSBUSART = putrsUSBUSART;
    bl_interface.putsUSBUSART = putsUSBUSART;
    bl_interface.USBUSARTIsTxTrfReady = fUSBUSARTIsTxTrfReady;
}

uint32_t bl_read_memory(uint32_t address) {

    uint32_t data_h, data_l;
    
    TBLPAG = address >> 16;
    
    data_l = (uint32_t) __builtin_tblrdl((uint16_t) address);
    data_h = (uint32_t) __builtin_tblrdh((uint16_t) address) << 16;

    return data_h + data_l;
}

void bl_write_memory(uint32_t address, uint32_t data) {
    uint16_t data_h, data_l, offset;

    TBLPAG = address >> 16;
    offset = address;
    
    data_h = data >> 16;
    data_l = data;
    
    NVMCON = 0x4003;
    __builtin_tblwtl(offset, data_l);
    __builtin_tblwth(offset, data_h);
    __builtin_write_NVM();
    NVMCON = 0;
}

void bl_write_chunk(uint32_t address, uint32_t data[64]) {
    uint16_t offset;
    uint8_t i;
    
    NVMCON = 0x4001;
    TBLPAG = address >> 16;
    offset = (uint16_t) address;

    for(i=0; i<64; i++) {
        __builtin_tblwtl(offset, *data);
        __builtin_tblwth(offset, *data >> 16);
        offset += 2;
        data++;
    }
    
    asm("DISI #5");
    __builtin_write_NVM();
    while(NVMCONbits.WR);
    NVMCON = 0;
}

void bl_erase (uint32_t address) {
    uint16_t offset;

    TBLPAG = address >> 16;
    offset = address;
    __builtin_tblwtl(offset, 0x0000);
    
    NVMCON = 0x4042;
    asm("DISI #5");
    __builtin_write_NVM();
    NVMCON = 0;
}

