/* 
 * File:   main.h
 * Author: philippe
 *
 * Created on May 7, 2016, 11:19 AM
 */

#ifndef MAIN_H
#define	MAIN_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <stdbool.h>

void init_device(void);
void heartBeat(void);
void mon_putc (char c);
void CDCTasks(void);
void TerminalTasks(void);
bool fUSBUSARTIsTxTrfReady (void);

#ifdef	__cplusplus
}
#endif

#endif	/* MAIN_H */

