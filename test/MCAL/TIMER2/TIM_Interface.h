/*
 * TIM_Interface.h
 *
 * Created: 9/5/2022 5:43:50 PM
 *  Author: XPNET
 */ 


#ifndef TIM_INTERFACE_H_
#define TIM_INTERFACE_H_

typedef enum {
	TIM2_CS_STOP, TIM2_CS_DIV_1, TIM2_CS_DIV_8, TIM2_CS_DIV_64, TIM2_CS_DIV_256, TIM2_CS_DIV_1024, TIM2_CS_TO_FALLING, TIM2_CS_TO_RISING
}TIM2ClockSource;

typedef enum {
	TIM2_MODE_NORMAL, TIM2_MODE_PCPWM, TIM2_MODE_CTC, TIM2_MODE_FPWM
}TIM2Mode;

typedef enum {
	TIM2_CTC_DIS, TIM2_CTC_TOG, TIM2_CTC_CLR, TIM2_CTC_SET
}TIM2CTC;
	
typedef enum {
	TIM2_PCPWM_DIS, TIM2_PCPWM_NON_INVERT=2, TIM2_PCPWM_INVERT
}TIM2PCPWM;
	
typedef enum {
	TIM2_FPWM_DIS, TIM2_FPWM_NON_INVERT=2, TIM2_FPWM_INVERT
}TIM2FPWM;
	
typedef enum {
	TIM2_INTERRUPT_OVERFLOW, TIM2_INTERRUPT_COMPARE
}TIM2Interrupt;
	
void MTIM2_voidInit(TIM2ClockSource ClockSourse, TIM2Mode Mode, u8 Channel, u8 Preload);

u8 MTIM2_u8GetCounter(void);

void MTIM2_voidSetCounter(u8 CounterValue);

void MTIM2_voidStart(void);

void MTIM2_voidStop(void);

//DutyCycle will be a number   
void MTIM2_voidSetDutyCycle(u8 DutyCycle);

//set CTC Frequency
void MTIM2_voidSetFrequency(u32 );

void MTIM2_voidDelay(u8 TimeTicks);
//
//void MTIM2_voidPeriodicInterupt(u8 TimeTicks, void(*CallBack)(void));
//
//void MTIM2_voidSingleInterupt(u8 TimeTicks, void(*CallBack)(void));
//
//void MTIM2_voidStopPeriodicInterrupt(void);

void MTIM2_voidEnableInteruppet(TIM2Interrupt Interrupt);

void MTIM2_voidDisableInteruppet(TIM2Interrupt Interrupt);

void MTIM2_voidSetCallBack(TIM2Interrupt Interrupt, void(*CallBack)(void));



#endif /* TIM_INTERFACE_H_ */