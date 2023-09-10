/*
 * TIM_Private.h
 *
 * Created: 9/5/2022 5:44:11 PM
 *  Author: XPNET
 */ 


#ifndef TIM_PRIVATE_H_
#define TIM_PRIVATE_H_

#define TIMSK_REG			(*(volatile u8*)0x59)
#define TIFR_REG			(*(volatile u8*)0x58)

#define TCCR2_REG			(*(volatile u8*)0x45)
#define TCNT2_REG			(*(volatile u8*)0x44)
#define OCR2_REG			(*(volatile u8*)0x43)

#define TIM2_ISR_VECTOR_OVERFLOW			__vector_4
#define TIM2_ISR_VECTOR_COMPARE				__vector_3

void TIM2_ISR_VECTOR_OVERFLOW(void)	__attribute__((signal,used));
void TIM2_ISR_VECTOR_COMPARE(void)	__attribute__((signal,used));

void (*PTIM2CallBacks[2])(void) = {0,0};

u8 PTIM2ClockSource = 0;
u16 PTIM2Prescalars[5] = {1,8,64,256,1024};

#endif /* TIM_PRIVATE_H_ */