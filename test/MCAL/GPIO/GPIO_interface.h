/*
 * GPIO_interface.h
 *
 * Created: 8/6/2022 1:29:46 AM
 *  Author: XPNET
 */ 


#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

enum PortID_t {GPIO_PORTA, GPIO_PORTB, GPIO_PORTC, GPIO_PORTD};
enum Direction_t{GPIO_INPUT, GPIO_OUTPUT, GPIO_INPUT_PULLUP};
enum GPIO_State_t{GPIO_LOW, GPIO_HIGH};
	
void MGPIO_voidSetPinDirection (enum PortID_t PortID, u8 PinNumber, enum Direction_t Dircection);
void MGPIO_voidSetPinValue(enum PortID_t PortID, u8 PinNumber, enum GPIO_State_t Value);

void MGPIO_voidSetPortDirection (enum PortID_t PortID, enum Direction_t Dircection);
void MGPIO_voidSetPortValue(enum PortID_t PortID, u8 Value);

void MGPIO_voidTogglePin(enum PortID_t PortID, u8 PinNumber);
void MGPIO_voidTogglePort(enum PortID_t PortID);

u8 MGPIO_u8GetPinValue(enum PortID_t PortID, u8 PinNumber);
u8 MGPIO_u8GetPortValue(enum PortID_t PortID);




#endif /* GPIO_INTERFACE_H_ */