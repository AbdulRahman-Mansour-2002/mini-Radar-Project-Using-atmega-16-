/*
 * BIT_MATH.h
 *
 * Created: 8/6/2022 1:41:22 AM
 *  Author: XPNET
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_bit(VAR,BIT)       (VAR |= (1<<BIT))
#define CLR_bit(VAR,BIT)       (VAR &= ~(1<<BIT))
#define TOG_bit(VAR,BIT)       (VAR ^= (1<<BIT))
#define GET_bit(VAR,BIT)       ((VAR>>BIT) & 1)

#define SET_REG(REG)		   (REG = 255)
#define CLR_REG(REG)           (REG = 0)
#define TOG_REG(REG)           (REG ^= 255)

#define SET_DWORD(DWORD)		   (DWORD = 0xFFFF)
#define CLR_DWORD(DWORD)		   (DWORD = 0)
#define TOG_DWORD(DWORD)		   (DWORD ^= 0xFFFF)



#endif /* BIT_MATH_H_ */


