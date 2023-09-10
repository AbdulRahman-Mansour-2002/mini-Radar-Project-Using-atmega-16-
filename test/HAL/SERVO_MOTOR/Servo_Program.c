
/*
 * Servo_Program.c
 *
 * Created: 9/7/2022 11:02:09 AM
 *  Author: XPNET
 */ 
#include "../../MCAL/GPIO/STD_TYPES.h"
#include "../../MCAL/GPIO/BIT_MATH.h"

#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../MCAL/CLOCK/Clock_Interface.h"
#include "../../MCAL/TIMER2/TIM_Interface.h"

#include "Servo_InterFace.h"
#include "Servo_Private.h"

void HSERVO_voidInit(servo_t* S)
{
	MGPIO_voidSetPinDirection(S->Port,S->Pin,GPIO_OUTPUT);      //set pin as output
	//u8 Duty = 255*1.5*S->PWMFrequency/1000;						
	//MTIM2_voidSetDutyCycle(Duty);
}

void HSERVO_voidGoToAngle(u8 Angle)
{
	u8 AngOCR = (((u16)Angle)*255)/180;
	MTIM2_voidSetDutyCycle(AngOCR);
}

void HSERVO_voidMotion()
{
	u8 angle =0;
	while(1){
	while(angle !=180){
		MGPIO_voidSetPinValue(GPIO_PORTC,1,GPIO_HIGH);
		MGPIO_voidSetPinValue(GPIO_PORTC,0,GPIO_LOW);
		HSERVO_voidGoToAngle(angle++);
		MCLOCK_voidDelayMS(10);
	}
	while(angle !=1){
		MGPIO_voidSetPinValue(GPIO_PORTC,0,GPIO_HIGH);
		MGPIO_voidSetPinValue(GPIO_PORTC,1,GPIO_LOW);
		HSERVO_voidGoToAngle(angle--);
		MCLOCK_voidDelayMS(10);
	}
	}
}