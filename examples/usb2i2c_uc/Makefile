SRC = usb2i2c.c usb_descriptors.c usb_device.c hardware.c usb_fonctions.c acm.c managerUtility.c
OBJ = build/usb2i2c.o build/usb_descriptors.o build/usb_device.o build/hardware.o build/usb_fonctions.o build/acm.o build/managerUtility.o
FIRMWARE = usb2i2c

BUILD = build
MCPU = 24FJ128GB202
LINKER_SCRIPT = p24FJ128GB202.gld

HFLAGS = -a -omf=elf  
CFLAGS = -mcpu=$(MCPU) -omf=elf -legacy-libc -I./usb/ -I.
LFLAGS = -Wl,--local-stack,--defsym=__MPLAB_BUILD=1,,--script=$(LINKER_SCRIPT),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map=$(BUILD)/$(FIRMWARE).map,--report-mem,--memorysummary,$(BUILD)/memoryfile.xml

CC = /opt/microchip/xc16/v1.26/bin/xc16-gcc
BIN2HEX = /opt/microchip/xc16/v1.26/bin/xc16-bin2hex
MV = mv
RM = rm -f
CP = cp

all: $(FIRMWARE)

$(BUILD)/%.o: %.c
	$(CC) $< -c -o $@ $(CFLAGS) 

$(FIRMWARE): $(OBJ)
	$(CC) -o $(BUILD)/$(FIRMWARE).elf $(LIB) $(OBJ) $(CFLAGS) $(LFLAGS)
	$(BIN2HEX) $(BUILD)/$(FIRMWARE).elf $(HFLAGS)
	#$(MV) $(BUILD)/$(FIRMWARE).hex .

clean:
	$(RM) $(BUILD)/* $(FIRMWARE).hex

upload:
	@echo Upload to eTower\(TM\): $<.hex
	java -jar /opt/microchip/mplabx/v3.30/mplab_ipe/ipecmd.jar -TPPK3 -P24FJ128GB202 -M -F`pwd`/build/usb2i2c.hex -OL
	rm MPLABXLog.xml.*
	rm log.0
