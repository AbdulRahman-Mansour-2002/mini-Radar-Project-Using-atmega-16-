/*
 * TIM_Program.c
 *
 * Created: 9/5/2022 5:43:30 PM
 *  Author: XPNET
 */ 
#include "../GPIO/STD_TYPES.h"
#include "../GPIO/BIT_MATH.h"

#include "../../MCAL/TIMER2/INTERRUPT.h"
#include "../../MCAL/CLOCK/Clock_Interface.h"

#include "TIM_Interface.h"
#include "TIM_Private.h"

void MTIM2_voidInit(TIM2ClockSource ClockSourse, TIM2Mode Mode, u8 Channel, u8 Preload)
{
	TCCR2_REG = 0;
	TCNT2_REG = Preload;
	OCR2_REG = 0;
	TIMSK_REG &= ~3;
	TCCR2_REG = (GET_bit(Mode,0)<<6) | (GET_bit(Mode,1) << 3) | (Channel << 4) | (ClockSourse);
	
	PTIM2ClockSource = ClockSourse;
}

u8 MTIM2_u8GetCounter(void)
{
	return TCNT2_REG;
}

void MTIM2_voidSetCounter(u8 CounterValue)
{
	TCNT2_REG = CounterValue;
}

void MTIM2_voidStart(void)
{
	TCCR2_REG |= PTIM2ClockSource;
}

void MTIM2_voidStop(void)
{
	TCCR2_REG &= ~7;
}

//DutyCycle will be a number between 0-> 255 representing a duty cycle 0 -> 100%
void MTIM2_voidSetDutyCycle(u8 DutyCycle)
{
	OCR2_REG = DutyCycle;
}

//set CTC Frequency
//fclk/(2*N*(1+OCR))  -> OCR = fclk / (2*N*freq)-1
void MTIM2_voidSetFrequency(u32 Frequency)
{
	if(PTIM2ClockSource > 5 && PTIM2ClockSource == 0)
		return;
	u32 CPU_Frequency =  MCLOCK_u32GetSystemClock();
	OCR2_REG = CPU_Frequency/(2*Frequency*PTIM2Prescalars[PTIM2ClockSource-1]) -1;
}

void MTIM2_voidDelay(u8 TimeTicks)
{
	TCNT2_REG =0;
	while(TCNT2_REG < TimeTicks);
}

void MTIM2_voidEnableInteruppet(TIM2Interrupt Interrupt)
{
	SET_bit(TIMSK_REG,Interrupt);
	//TIMSK_REG |= 1<<Interrupt;
	INTERRUPT_ENABLE_GLOBAL_INTERRUPT;
}

void MTIM2_voidDisableInteruppet(TIM2Interrupt Interrupt)
{
	CLR_bit(TIMSK_REG,Interrupt);
	//TIMSK_REG &= ~(1<<Interrupt);
}

void MTIM0_voidSetCallBack(TIM2Interrupt Interrrupt, void(*CallBack)(void))
{
	if(Interrrupt >1)
		return;
	PTIM2CallBacks[Interrrupt] = CallBack;
}

void TIM2_ISR_VECTOR_OVERFLOW(void)
{
	if(PTIM2CallBacks[0] != 0)
	{
		PTIM2CallBacks[0]();
	}
	SET_bit(TIFR_REG,0);
}
void TIM2_ISR_VECTOR_COMPARE(void)
{
	if(PTIM2CallBacks[1] != 0)
	{
		PTIM2CallBacks[1]();
	}
	SET_bit(TIFR_REG,1);
}