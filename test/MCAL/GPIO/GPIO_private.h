/*
 * GPIO_private.h
 *
 * Created: 8/6/2022 1:29:17 AM
 *  Author: XPNET
 */ 


#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

typedef struct{
	u8 PIN;
	u8 DDR;
	u8 PORT;
}PORT_t;

#define PORTA_REG			((volatile PORT_t*)(0x39)) 
#define PORTB_REG			((volatile PORT_t*)(0x36)) 
#define PORTC_REG			((volatile PORT_t*)(0x33)) 
#define PORTD_REG			((volatile PORT_t*)(0x30 )) 


#endif /* GPIO_PRIVATE_H_ */