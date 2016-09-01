#ifndef TCPIP_CONFIG_H
#define	TCPIP_CONFIG_H

#define strlenpgm strlen
#define TCP_PURPOSE_TELNET 0
#define TCP_PURPOSE_ETOWER 1

#define GetInstructionClock() 32000000u
#define GetPeripheralClock() 32000000u
#define SYS_CLK_FrequencyInstructionGet(x) 32000000u
#define SYS_CLK_FrequencyPeripheralGet(x) 32000000u

#define ROM const
#define MAX_UDP_SOCKETS 2
#define MAX_HTTP_CONNECTIONS 2

#define STACK_USE_ICMP_SERVER
#define STACK_USE_ICMP_CLIENT
//#define STACK_CLIENT_MODE
#define STACK_USE_DHCP_CLIENT
#define STACK_USE_TCP
#define STACK_USE_TELNET_SERVER

#define MY_DEFAULT_IP_ADDR_BYTE1        (192ul)
#define MY_DEFAULT_IP_ADDR_BYTE2        (168ul)
#define MY_DEFAULT_IP_ADDR_BYTE3        (0ul)
#define MY_DEFAULT_IP_ADDR_BYTE4        (250ul)

#include "tcpip/src/enc28j60.h"
#include "HardwareProfile.h"
#include "tcpip/tcpip.h"
#include "tcpEtower.h"
#include "usb_fonctions.h" // for debug purpose


#if defined(__TCP_C_)
const struct {
	BYTE vSocketPurpose;
	BYTE vMemoryMedium;
	WORD wTXBufferSize;
	WORD wRXBufferSize;
} TCPSocketInitializer[] = {
	{TCP_PURPOSE_TELNET, TCP_ETH_RAM, 200, 150},
	{TCP_PURPOSE_TELNET, TCP_ETH_RAM, 200, 150},
	{TCP_PURPOSE_TELNET, TCP_ETH_RAM, 200, 150},
    {TCP_PURPOSE_ETOWER, TCP_ETH_RAM, 600, 100},
};
#endif

#endif /* TCPIP_CONFIG_H */