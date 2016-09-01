#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=mkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/EthernetENC28J60.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/EthernetENC28J60.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=tcpip/src/arp.c tcpip/src/common/delay.c ENC28J60.c tcpip/src/common/helpers.c tcpip/src/icmp.c tcpip/src/ip.c tcpip/src/common/stack_task.c tcpip/src/common/tick.c tcpip/src/udp.c tcpip/src/tcp.c tcpip/src/dhcp_client.c tcpip/src/telnet.c usb_descriptors.c usb/src/usb_device.c usb/src/usb_device_generic.c usb_fonctions.c EthernetENCJ28J60.c mcc_generated_files/pin_manager.c tcpEtower.c irtx.c irrx.c terminal.c ir.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/tcpip/src/arp.o ${OBJECTDIR}/tcpip/src/common/delay.o ${OBJECTDIR}/ENC28J60.o ${OBJECTDIR}/tcpip/src/common/helpers.o ${OBJECTDIR}/tcpip/src/icmp.o ${OBJECTDIR}/tcpip/src/ip.o ${OBJECTDIR}/tcpip/src/common/stack_task.o ${OBJECTDIR}/tcpip/src/common/tick.o ${OBJECTDIR}/tcpip/src/udp.o ${OBJECTDIR}/tcpip/src/tcp.o ${OBJECTDIR}/tcpip/src/dhcp_client.o ${OBJECTDIR}/tcpip/src/telnet.o ${OBJECTDIR}/usb_descriptors.o ${OBJECTDIR}/usb/src/usb_device.o ${OBJECTDIR}/usb/src/usb_device_generic.o ${OBJECTDIR}/usb_fonctions.o ${OBJECTDIR}/EthernetENCJ28J60.o ${OBJECTDIR}/mcc_generated_files/pin_manager.o ${OBJECTDIR}/tcpEtower.o ${OBJECTDIR}/irtx.o ${OBJECTDIR}/irrx.o ${OBJECTDIR}/terminal.o ${OBJECTDIR}/ir.o
POSSIBLE_DEPFILES=${OBJECTDIR}/tcpip/src/arp.o.d ${OBJECTDIR}/tcpip/src/common/delay.o.d ${OBJECTDIR}/ENC28J60.o.d ${OBJECTDIR}/tcpip/src/common/helpers.o.d ${OBJECTDIR}/tcpip/src/icmp.o.d ${OBJECTDIR}/tcpip/src/ip.o.d ${OBJECTDIR}/tcpip/src/common/stack_task.o.d ${OBJECTDIR}/tcpip/src/common/tick.o.d ${OBJECTDIR}/tcpip/src/udp.o.d ${OBJECTDIR}/tcpip/src/tcp.o.d ${OBJECTDIR}/tcpip/src/dhcp_client.o.d ${OBJECTDIR}/tcpip/src/telnet.o.d ${OBJECTDIR}/usb_descriptors.o.d ${OBJECTDIR}/usb/src/usb_device.o.d ${OBJECTDIR}/usb/src/usb_device_generic.o.d ${OBJECTDIR}/usb_fonctions.o.d ${OBJECTDIR}/EthernetENCJ28J60.o.d ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d ${OBJECTDIR}/tcpEtower.o.d ${OBJECTDIR}/irtx.o.d ${OBJECTDIR}/irrx.o.d ${OBJECTDIR}/terminal.o.d ${OBJECTDIR}/ir.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/tcpip/src/arp.o ${OBJECTDIR}/tcpip/src/common/delay.o ${OBJECTDIR}/ENC28J60.o ${OBJECTDIR}/tcpip/src/common/helpers.o ${OBJECTDIR}/tcpip/src/icmp.o ${OBJECTDIR}/tcpip/src/ip.o ${OBJECTDIR}/tcpip/src/common/stack_task.o ${OBJECTDIR}/tcpip/src/common/tick.o ${OBJECTDIR}/tcpip/src/udp.o ${OBJECTDIR}/tcpip/src/tcp.o ${OBJECTDIR}/tcpip/src/dhcp_client.o ${OBJECTDIR}/tcpip/src/telnet.o ${OBJECTDIR}/usb_descriptors.o ${OBJECTDIR}/usb/src/usb_device.o ${OBJECTDIR}/usb/src/usb_device_generic.o ${OBJECTDIR}/usb_fonctions.o ${OBJECTDIR}/EthernetENCJ28J60.o ${OBJECTDIR}/mcc_generated_files/pin_manager.o ${OBJECTDIR}/tcpEtower.o ${OBJECTDIR}/irtx.o ${OBJECTDIR}/irrx.o ${OBJECTDIR}/terminal.o ${OBJECTDIR}/ir.o

# Source Files
SOURCEFILES=tcpip/src/arp.c tcpip/src/common/delay.c ENC28J60.c tcpip/src/common/helpers.c tcpip/src/icmp.c tcpip/src/ip.c tcpip/src/common/stack_task.c tcpip/src/common/tick.c tcpip/src/udp.c tcpip/src/tcp.c tcpip/src/dhcp_client.c tcpip/src/telnet.c usb_descriptors.c usb/src/usb_device.c usb/src/usb_device_generic.c usb_fonctions.c EthernetENCJ28J60.c mcc_generated_files/pin_manager.c tcpEtower.c irtx.c irrx.c terminal.c ir.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/EthernetENC28J60.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ128GB202
MP_LINKER_FILE_OPTION=,--script=p24FJ128GB202.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/tcpip/src/arp.o: tcpip/src/arp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/tcpip/src" 
	@${RM} ${OBJECTDIR}/tcpip/src/arp.o.d 
	@${RM} ${OBJECTDIR}/tcpip/src/arp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  tcpip/src/arp.c  -o ${OBJECTDIR}/tcpip/src/arp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/tcpip/src/arp.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/tcpip/src/arp.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/tcpip/src/common/delay.o: tcpip/src/common/delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/tcpip/src/common/delay.o.d 
	@${RM} ${OBJECTDIR}/tcpip/src/common/delay.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  tcpip/src/common/delay.c  -o ${OBJECTDIR}/tcpip/src/common/delay.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/tcpip/src/common/delay.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/tcpip/src/common/delay.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ENC28J60.o: ENC28J60.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ENC28J60.o.d 
	@${RM} ${OBJECTDIR}/ENC28J60.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ENC28J60.c  -o ${OBJECTDIR}/ENC28J60.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ENC28J60.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/ENC28J60.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/tcpip/src/common/helpers.o: tcpip/src/common/helpers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/tcpip/src/common/helpers.o.d 
	@${RM} ${OBJECTDIR}/tcpip/src/common/helpers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  tcpip/src/common/helpers.c  -o ${OBJECTDIR}/tcpip/src/common/helpers.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/tcpip/src/common/helpers.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/tcpip/src/common/helpers.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/tcpip/src/icmp.o: tcpip/src/icmp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/tcpip/src" 
	@${RM} ${OBJECTDIR}/tcpip/src/icmp.o.d 
	@${RM} ${OBJECTDIR}/tcpip/src/icmp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  tcpip/src/icmp.c  -o ${OBJECTDIR}/tcpip/src/icmp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/tcpip/src/icmp.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/tcpip/src/icmp.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/tcpip/src/ip.o: tcpip/src/ip.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/tcpip/src" 
	@${RM} ${OBJECTDIR}/tcpip/src/ip.o.d 
	@${RM} ${OBJECTDIR}/tcpip/src/ip.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  tcpip/src/ip.c  -o ${OBJECTDIR}/tcpip/src/ip.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/tcpip/src/ip.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/tcpip/src/ip.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/tcpip/src/common/stack_task.o: tcpip/src/common/stack_task.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/tcpip/src/common/stack_task.o.d 
	@${RM} ${OBJECTDIR}/tcpip/src/common/stack_task.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  tcpip/src/common/stack_task.c  -o ${OBJECTDIR}/tcpip/src/common/stack_task.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/tcpip/src/common/stack_task.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/tcpip/src/common/stack_task.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/tcpip/src/common/tick.o: tcpip/src/common/tick.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/tcpip/src/common/tick.o.d 
	@${RM} ${OBJECTDIR}/tcpip/src/common/tick.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  tcpip/src/common/tick.c  -o ${OBJECTDIR}/tcpip/src/common/tick.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/tcpip/src/common/tick.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/tcpip/src/common/tick.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/tcpip/src/udp.o: tcpip/src/udp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/tcpip/src" 
	@${RM} ${OBJECTDIR}/tcpip/src/udp.o.d 
	@${RM} ${OBJECTDIR}/tcpip/src/udp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  tcpip/src/udp.c  -o ${OBJECTDIR}/tcpip/src/udp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/tcpip/src/udp.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/tcpip/src/udp.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/tcpip/src/tcp.o: tcpip/src/tcp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/tcpip/src" 
	@${RM} ${OBJECTDIR}/tcpip/src/tcp.o.d 
	@${RM} ${OBJECTDIR}/tcpip/src/tcp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  tcpip/src/tcp.c  -o ${OBJECTDIR}/tcpip/src/tcp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/tcpip/src/tcp.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/tcpip/src/tcp.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/tcpip/src/dhcp_client.o: tcpip/src/dhcp_client.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/tcpip/src" 
	@${RM} ${OBJECTDIR}/tcpip/src/dhcp_client.o.d 
	@${RM} ${OBJECTDIR}/tcpip/src/dhcp_client.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  tcpip/src/dhcp_client.c  -o ${OBJECTDIR}/tcpip/src/dhcp_client.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/tcpip/src/dhcp_client.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/tcpip/src/dhcp_client.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/tcpip/src/telnet.o: tcpip/src/telnet.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/tcpip/src" 
	@${RM} ${OBJECTDIR}/tcpip/src/telnet.o.d 
	@${RM} ${OBJECTDIR}/tcpip/src/telnet.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  tcpip/src/telnet.c  -o ${OBJECTDIR}/tcpip/src/telnet.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/tcpip/src/telnet.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/tcpip/src/telnet.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/usb_descriptors.o: usb_descriptors.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/usb_descriptors.o.d 
	@${RM} ${OBJECTDIR}/usb_descriptors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  usb_descriptors.c  -o ${OBJECTDIR}/usb_descriptors.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/usb_descriptors.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/usb_descriptors.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/usb/src/usb_device.o: usb/src/usb_device.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_device.o.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_device.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  usb/src/usb_device.c  -o ${OBJECTDIR}/usb/src/usb_device.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/usb/src/usb_device.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/usb/src/usb_device.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/usb/src/usb_device_generic.o: usb/src/usb_device_generic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_generic.o.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_generic.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  usb/src/usb_device_generic.c  -o ${OBJECTDIR}/usb/src/usb_device_generic.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/usb/src/usb_device_generic.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/usb/src/usb_device_generic.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/usb_fonctions.o: usb_fonctions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/usb_fonctions.o.d 
	@${RM} ${OBJECTDIR}/usb_fonctions.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  usb_fonctions.c  -o ${OBJECTDIR}/usb_fonctions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/usb_fonctions.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/usb_fonctions.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/EthernetENCJ28J60.o: EthernetENCJ28J60.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EthernetENCJ28J60.o.d 
	@${RM} ${OBJECTDIR}/EthernetENCJ28J60.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  EthernetENCJ28J60.c  -o ${OBJECTDIR}/EthernetENCJ28J60.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/EthernetENCJ28J60.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/EthernetENCJ28J60.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/mcc_generated_files/pin_manager.o: mcc_generated_files/pin_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/pin_manager.c  -o ${OBJECTDIR}/mcc_generated_files/pin_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/mcc_generated_files/pin_manager.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/mcc_generated_files/pin_manager.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/tcpEtower.o: tcpEtower.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/tcpEtower.o.d 
	@${RM} ${OBJECTDIR}/tcpEtower.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  tcpEtower.c  -o ${OBJECTDIR}/tcpEtower.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/tcpEtower.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/tcpEtower.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/irtx.o: irtx.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/irtx.o.d 
	@${RM} ${OBJECTDIR}/irtx.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  irtx.c  -o ${OBJECTDIR}/irtx.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/irtx.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/irtx.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/irrx.o: irrx.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/irrx.o.d 
	@${RM} ${OBJECTDIR}/irrx.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  irrx.c  -o ${OBJECTDIR}/irrx.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/irrx.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/irrx.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/terminal.o: terminal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/terminal.o.d 
	@${RM} ${OBJECTDIR}/terminal.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  terminal.c  -o ${OBJECTDIR}/terminal.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/terminal.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/terminal.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ir.o: ir.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ir.o.d 
	@${RM} ${OBJECTDIR}/ir.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ir.c  -o ${OBJECTDIR}/ir.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ir.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -mno-eds-warn  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/ir.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/tcpip/src/arp.o: tcpip/src/arp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/tcpip/src" 
	@${RM} ${OBJECTDIR}/tcpip/src/arp.o.d 
	@${RM} ${OBJECTDIR}/tcpip/src/arp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  tcpip/src/arp.c  -o ${OBJECTDIR}/tcpip/src/arp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/tcpip/src/arp.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/tcpip/src/arp.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/tcpip/src/common/delay.o: tcpip/src/common/delay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/tcpip/src/common/delay.o.d 
	@${RM} ${OBJECTDIR}/tcpip/src/common/delay.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  tcpip/src/common/delay.c  -o ${OBJECTDIR}/tcpip/src/common/delay.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/tcpip/src/common/delay.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/tcpip/src/common/delay.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ENC28J60.o: ENC28J60.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ENC28J60.o.d 
	@${RM} ${OBJECTDIR}/ENC28J60.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ENC28J60.c  -o ${OBJECTDIR}/ENC28J60.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ENC28J60.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/ENC28J60.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/tcpip/src/common/helpers.o: tcpip/src/common/helpers.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/tcpip/src/common/helpers.o.d 
	@${RM} ${OBJECTDIR}/tcpip/src/common/helpers.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  tcpip/src/common/helpers.c  -o ${OBJECTDIR}/tcpip/src/common/helpers.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/tcpip/src/common/helpers.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/tcpip/src/common/helpers.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/tcpip/src/icmp.o: tcpip/src/icmp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/tcpip/src" 
	@${RM} ${OBJECTDIR}/tcpip/src/icmp.o.d 
	@${RM} ${OBJECTDIR}/tcpip/src/icmp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  tcpip/src/icmp.c  -o ${OBJECTDIR}/tcpip/src/icmp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/tcpip/src/icmp.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/tcpip/src/icmp.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/tcpip/src/ip.o: tcpip/src/ip.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/tcpip/src" 
	@${RM} ${OBJECTDIR}/tcpip/src/ip.o.d 
	@${RM} ${OBJECTDIR}/tcpip/src/ip.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  tcpip/src/ip.c  -o ${OBJECTDIR}/tcpip/src/ip.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/tcpip/src/ip.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/tcpip/src/ip.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/tcpip/src/common/stack_task.o: tcpip/src/common/stack_task.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/tcpip/src/common/stack_task.o.d 
	@${RM} ${OBJECTDIR}/tcpip/src/common/stack_task.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  tcpip/src/common/stack_task.c  -o ${OBJECTDIR}/tcpip/src/common/stack_task.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/tcpip/src/common/stack_task.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/tcpip/src/common/stack_task.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/tcpip/src/common/tick.o: tcpip/src/common/tick.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/tcpip/src/common" 
	@${RM} ${OBJECTDIR}/tcpip/src/common/tick.o.d 
	@${RM} ${OBJECTDIR}/tcpip/src/common/tick.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  tcpip/src/common/tick.c  -o ${OBJECTDIR}/tcpip/src/common/tick.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/tcpip/src/common/tick.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/tcpip/src/common/tick.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/tcpip/src/udp.o: tcpip/src/udp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/tcpip/src" 
	@${RM} ${OBJECTDIR}/tcpip/src/udp.o.d 
	@${RM} ${OBJECTDIR}/tcpip/src/udp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  tcpip/src/udp.c  -o ${OBJECTDIR}/tcpip/src/udp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/tcpip/src/udp.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/tcpip/src/udp.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/tcpip/src/tcp.o: tcpip/src/tcp.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/tcpip/src" 
	@${RM} ${OBJECTDIR}/tcpip/src/tcp.o.d 
	@${RM} ${OBJECTDIR}/tcpip/src/tcp.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  tcpip/src/tcp.c  -o ${OBJECTDIR}/tcpip/src/tcp.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/tcpip/src/tcp.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/tcpip/src/tcp.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/tcpip/src/dhcp_client.o: tcpip/src/dhcp_client.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/tcpip/src" 
	@${RM} ${OBJECTDIR}/tcpip/src/dhcp_client.o.d 
	@${RM} ${OBJECTDIR}/tcpip/src/dhcp_client.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  tcpip/src/dhcp_client.c  -o ${OBJECTDIR}/tcpip/src/dhcp_client.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/tcpip/src/dhcp_client.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/tcpip/src/dhcp_client.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/tcpip/src/telnet.o: tcpip/src/telnet.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/tcpip/src" 
	@${RM} ${OBJECTDIR}/tcpip/src/telnet.o.d 
	@${RM} ${OBJECTDIR}/tcpip/src/telnet.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  tcpip/src/telnet.c  -o ${OBJECTDIR}/tcpip/src/telnet.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/tcpip/src/telnet.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/tcpip/src/telnet.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/usb_descriptors.o: usb_descriptors.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/usb_descriptors.o.d 
	@${RM} ${OBJECTDIR}/usb_descriptors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  usb_descriptors.c  -o ${OBJECTDIR}/usb_descriptors.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/usb_descriptors.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/usb_descriptors.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/usb/src/usb_device.o: usb/src/usb_device.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_device.o.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_device.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  usb/src/usb_device.c  -o ${OBJECTDIR}/usb/src/usb_device.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/usb/src/usb_device.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/usb/src/usb_device.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/usb/src/usb_device_generic.o: usb/src/usb_device_generic.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/usb/src" 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_generic.o.d 
	@${RM} ${OBJECTDIR}/usb/src/usb_device_generic.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  usb/src/usb_device_generic.c  -o ${OBJECTDIR}/usb/src/usb_device_generic.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/usb/src/usb_device_generic.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/usb/src/usb_device_generic.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/usb_fonctions.o: usb_fonctions.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/usb_fonctions.o.d 
	@${RM} ${OBJECTDIR}/usb_fonctions.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  usb_fonctions.c  -o ${OBJECTDIR}/usb_fonctions.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/usb_fonctions.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/usb_fonctions.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/EthernetENCJ28J60.o: EthernetENCJ28J60.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/EthernetENCJ28J60.o.d 
	@${RM} ${OBJECTDIR}/EthernetENCJ28J60.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  EthernetENCJ28J60.c  -o ${OBJECTDIR}/EthernetENCJ28J60.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/EthernetENCJ28J60.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/EthernetENCJ28J60.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/mcc_generated_files/pin_manager.o: mcc_generated_files/pin_manager.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/mcc_generated_files" 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o.d 
	@${RM} ${OBJECTDIR}/mcc_generated_files/pin_manager.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  mcc_generated_files/pin_manager.c  -o ${OBJECTDIR}/mcc_generated_files/pin_manager.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/mcc_generated_files/pin_manager.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/mcc_generated_files/pin_manager.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/tcpEtower.o: tcpEtower.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/tcpEtower.o.d 
	@${RM} ${OBJECTDIR}/tcpEtower.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  tcpEtower.c  -o ${OBJECTDIR}/tcpEtower.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/tcpEtower.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/tcpEtower.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/irtx.o: irtx.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/irtx.o.d 
	@${RM} ${OBJECTDIR}/irtx.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  irtx.c  -o ${OBJECTDIR}/irtx.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/irtx.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/irtx.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/irrx.o: irrx.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/irrx.o.d 
	@${RM} ${OBJECTDIR}/irrx.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  irrx.c  -o ${OBJECTDIR}/irrx.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/irrx.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/irrx.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/terminal.o: terminal.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/terminal.o.d 
	@${RM} ${OBJECTDIR}/terminal.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  terminal.c  -o ${OBJECTDIR}/terminal.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/terminal.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/terminal.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/ir.o: ir.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ir.o.d 
	@${RM} ${OBJECTDIR}/ir.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ir.c  -o ${OBJECTDIR}/ir.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/ir.o.d"      -mno-eds-warn  -g -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -O0 -I"./" -I"./usb" -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/ir.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/EthernetENC28J60.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    p24FJ128GB202.gld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/EthernetENC28J60.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)   -mreserve=data@0x800:0x81B -mreserve=data@0x81C:0x81D -mreserve=data@0x81E:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x827 -mreserve=data@0x82A:0x84F   -Wl,--local-stack,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_PK3=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/EthernetENC28J60.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   p24FJ128GB202.gld
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/EthernetENC28J60.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -no-legacy-libc  $(COMPARISON_BUILD)  -Wl,--local-stack,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem,--memorysummary,dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}/xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/EthernetENC28J60.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf  
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell "${PATH_TO_IDE_BIN}"mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
