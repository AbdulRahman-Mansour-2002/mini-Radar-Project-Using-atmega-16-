/*
 * GPIO_program.c
 *
 * Created: 8/6/2022 1:28:47 AM
 *  Author: XPNET
 */ 

//#include <avr/io.h>

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "GPIO_private.h"

PORT_t* PGPIO_PORT_tPtr_GetRegister(enum PortID_t PortID){
	switch(PortID)
	{
		case GPIO_PORTA:
			return PORTA_REG;
		case GPIO_PORTB:
			return PORTB_REG;
		case GPIO_PORTC:
			return PORTC_REG;
		case GPIO_PORTD:
			return PORTD_REG;
		default:
			return 0;
	}
}

void MGPIO_voidSetPinDirection (enum PortID_t PortID, u8 PinNumber, enum Direction_t Dircection)
{
	PORT_t * p =0;
	p =PGPIO_PORT_tPtr_GetRegister(PortID);
	if (Dircection == GPIO_INPUT){
		CLR_bit(p->DDR,PinNumber);
		CLR_bit(p->PORT,PinNumber);
	}
	else if(Dircection ==GPIO_OUTPUT){
		SET_bit(p->DDR,PinNumber);
		CLR_bit(p->PORT,PinNumber);
	}
	else if(Dircection == GPIO_INPUT_PULLUP){
		CLR_bit(p->DDR,PinNumber);
		SET_bit(p->PORT,PinNumber);
	}
}
void MGPIO_voidSetPinValue(enum PortID_t PortID, u8 PinNumber, enum GPIO_State_t Value)
{
	PORT_t* p =PGPIO_PORT_tPtr_GetRegister(PortID);
	if (Value == GPIO_LOW)
		CLR_bit(p->PORT,PinNumber);
	else if(Value == GPIO_HIGH)
		SET_bit(p->PORT,PinNumber);
}

void MGPIO_voidSetPortDirection (enum PortID_t PortID, enum Direction_t Dircection)
{
	PORT_t* p =PGPIO_PORT_tPtr_GetRegister(PortID);
	if(Dircection == GPIO_INPUT)
	{
		CLR_REG(p->DDR);
		CLR_REG(p->PORT);
	}
	else if(Dircection == GPIO_OUTPUT)
	{
		SET_REG(p->DDR);
		CLR_REG(p->PORT);
	}
	else if(Dircection == GPIO_INPUT_PULLUP)
	{
		CLR_REG(p->DDR);
		SET_REG(p->PORT);
	}
}
void MGPIO_voidSetPortValue(enum PortID_t PortID, u8 Value){
	PORT_t* p =PGPIO_PORT_tPtr_GetRegister(PortID);
	p->PORT = Value;

}

void MGPIO_voidTogglePin(enum PortID_t PortID, u8 PinNumber)
{
	PORT_t* p =PGPIO_PORT_tPtr_GetRegister(PortID);
	TOG_bit(p->PORT,PinNumber);
}
void MGPIO_voidTogglePort(enum PortID_t PortID)
{
	PORT_t* p =PGPIO_PORT_tPtr_GetRegister(PortID);
	TOG_REG(p->PORT);
}

u8 MGPIO_u8GetPinValue(enum PortID_t PortID, u8 PinNumber){
	u8 Local_u8Val =0;
	PORT_t* p =PGPIO_PORT_tPtr_GetRegister(PortID);
	Local_u8Val =GET_bit(p->PIN,PinNumber);

	if (Local_u8Val)
		return GPIO_HIGH;
	else
		return GPIO_LOW;
}
u8 MGPIO_u8GetPortValue(enum PortID_t PortID){
	PORT_t* p =PGPIO_PORT_tPtr_GetRegister(PortID);
	u8 Local_u8Val =0;
	Local_u8Val = p->PIN;
	return Local_u8Val;
}

