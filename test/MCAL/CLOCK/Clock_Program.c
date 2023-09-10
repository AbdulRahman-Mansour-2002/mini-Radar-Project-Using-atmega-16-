/*
 * Clock_Program.c
 *
 * Created: 9/5/2022 10:24:28 PM
 *  Author: XPNET
 */ 
#include "../GPIO/STD_TYPES.h"
#include "../GPIO/BIT_MATH.h"

#include "../CLOCK/Clock_Interface.h"
#include "../CLOCK/Clock_Config.h"

void MCLOCK_voidDelayMS(u32 ms)
{
	register u32 Ticks = (CLOCK_SYSTEM_FREQUENCY/14000)*ms -10;
	while(Ticks--)
		__asm__ volatile("NOP");
}

//220000  in freq 16000000
//14000   in freq 1000000

u32 MCLOCK_u32GetSystemClock(void)
{
	return CLOCK_SYSTEM_FREQUENCY;
}