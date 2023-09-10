#ifndef _ULTRA_H_
#define _ULTRA_H_

#include<avr/io.h>
#include <avr/interrupt.h>
#include<string.h>
#include <stdlib.h>
#define F_CPU 1000000UL
#include <util/delay.h>
#include "../../MCAL/TIMER0/timer.h"


#define   TRIGER_DDR    DDRC
#define   ECHO_DDR      DDRD
#define   TRIGER_PORT   PORTC
#define   ECHO_PULLUP   PORTD
#define   TRIGER        0
#define   ECHO          3

/*************************************************
 *  API functions
 *************************************************/

void ultrasonic_init(void);
void enable_ex_interrupt(void);
void ultrasonic_triger(void);
void ultra_getangle(int Angle_Copy);
uint32_t ultra_getdist(void) ; 

#endif
