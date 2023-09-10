/*
 * INTERRUPT.h
 *
 * Created: 9/5/2022 7:14:30 AM
 *  Author: XPNET
 */ 


#ifndef INTERRUPT_H_
#define INTERRUPT_H_


#define	STATUS_REGISTER			(*(volatile u8*)0x5f)

#define	INTERRUPT_ENABLE_GLOBAL_INTERRUPT		(SET_bit(STATUS_REGISTER,7))
#define	INTERRUPT_DISABLE_GLOBAL_INTERRUPT		(SET_bit(STATUS_REGISTER,7))

#endif /* INTERRUPT_H_ */