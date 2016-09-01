#include "system_config.h"
#include "tcpip/tcpip.h"

#define SERVER_PORT 9760

static enum {
    SM_HOME = 0,
    SM_LISTENING,
    SM_CLOSING,
} TCPServerState = SM_HOME;

void eTowerTCPServerInit(void)
{
    TCPServerState = SM_CLOSING;
}

TCP_SOCKET MySocket = INVALID_SOCKET;
void eTowerTCPServer(void)
{
    uint8_t AppBuffer[64];
    uint16_t wMaxGet, wMaxPut;

    switch (TCPServerState) {
    case SM_HOME:
        // Allocate a socket for this server to listen and accept connections on
        MySocket = TCPOpen(0, TCP_OPEN_SERVER, SERVER_PORT, TCP_PURPOSE_ETOWER);
        if (MySocket == INVALID_SOCKET)
            return;
        TCPServerState = SM_LISTENING;
        break;

    case SM_LISTENING:
        // See if anyone is connected to us
        if (!TCPIsConnected(MySocket)) {
            return;
        }

        // Figure out how many bytes have been received and how many we can transmit.
        wMaxGet = TCPIsGetReady(MySocket); // Get TCP RX FIFO byte count
        wMaxPut = TCPIsPutReady(MySocket); // Get TCP TX FIFO free space

        if (wMaxGet) {
            TCPGetArray(MySocket, AppBuffer, wMaxGet);
            userHandlePacket((userPacket *) AppBuffer);
        }
        
        break;

    case SM_CLOSING:
        // Close the socket connection.
        TCPClose(MySocket);
        TCPServerState = SM_HOME;
        break;
    }
}

void eTowerTCPPrint(uint8_t* mystring){
    
    if (TCPServerState != SM_LISTENING)
        return;
    
    TCPPutString(MySocket, mystring); 
}

uint16_t eTowerTxAvailable(){
    return TCPIsPutReady(MySocket);
}

