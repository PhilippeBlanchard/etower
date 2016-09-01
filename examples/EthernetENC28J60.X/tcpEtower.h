/* 
 * File:   tcpEtower.h
 * Author: philippe
 *
 * Created on March 10, 2016, 2:19 PM
 */

#ifndef TCPETOWER_H
#define	TCPETOWER_H

#ifdef	__cplusplus
extern "C" {
#endif

void eTowerTCPServerInit(void);
void eTowerTCPServer(void);
void eTowerTCPPrint(uint8_t* mystring);
uint16_t eTowerTxAvailable();


#ifdef	__cplusplus
}
#endif

#endif	/* TCPETOWER_H */

