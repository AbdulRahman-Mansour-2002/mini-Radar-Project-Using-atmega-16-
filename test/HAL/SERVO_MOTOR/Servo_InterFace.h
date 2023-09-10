/*
 * Servo_InterFace.h
 *
 * Created: 9/7/2022 11:03:19 AM
 *  Author: XPNET
 */ 


#ifndef SERVO_INTERFACE_H_
#define SERVO_INTERFACE_H_

typedef struct
{
	enum PortID_t Port;
	u8 Pin;
	u32 PWMFrequency;
	
}servo_t;


void HSERVO_voidInit(servo_t* S);
void HSERVO_voidGoToAngle(u8 Angle);
void HSERVO_voidMotion();


#endif /* SERVO_INTERFACE_H_ */