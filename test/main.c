
#include "MCAL/GPIO/STD_TYPES.h"
#include "MCAL/GPIO/BIT_MATH.h"
#include "MCAL/UART/UART_interface.h"
#include "MCAL/GPIO/GPIO_interface.h"

#include "MCAL/CLOCK/Clock_Interface.h"
#include "MCAL/TIMER2/TIM_Interface.h"

#include "HAL/SERVO_MOTOR/Servo_InterFace.h"
#include  "HAL/lCD/LCD.h"
#include  "HAL/ULTRASONIC/ultrasonic.h"

//frequency = 10000000/(255*N)

int main(void)
{
	
	
	uint32_t DST = 4 ; 
	uint8_t dst_str[15]; 
	uint8_t angle_str[6]; 
	MGPIO_voidSetPinDirection(GPIO_PORTB,0,GPIO_OUTPUT);
	 UART_t UART0 = UART_UART_tInit(UART_Tx_or_Rx, UART_Async_NormalSpeed, UART_Single, UART_InterruptDisable, UART_8bitData,
	 UART_PArityDisable_1Stop, UART_RisingEdge, 4800);
	 
	
	MGPIO_voidSetPinDirection(GPIO_PORTD,7,GPIO_OUTPUT);
	MTIM2_voidInit(TIM2_CS_DIV_8,TIM2_MODE_PCPWM,TIM2_PCPWM_NON_INVERT,0);
	lcd_init();
	ultrasonic_init();
	sei();
	
	
	

// u8 var[] = "0.53";
// UART_voidTransmitString(var, UART0);





	_delay_ms(10);
	
	u8 angle =0;
	while(1){
		
		while(angle !=180){
			ultra_triger();
			HSERVO_voidGoToAngle(angle++);
			
				DST=ultra_getdist();
				if (DST <= 10)
				MGPIO_voidSetPinValue(GPIO_PORTB,0,GPIO_HIGH);
				else
				MGPIO_voidSetPinValue(GPIO_PORTB,0,GPIO_LOW);
				if (DST<4 || DST > 400 )DST=0;
				itoa(angle,(char*)angle_str,10);
				itoa(DST,(char*)dst_str,10);
				strcat((char*)dst_str, " "); strcat((char*)dst_str,angle_str);
				UART_voidTransmitString(dst_str,UART0);
		
		
				UART_voidTransmitByte('\n',UART0) ;
		
				//	ultra_getangle(angle);
				_delay_ms(14);
			
		}
		while(angle !=0){
				ultra_triger();
				HSERVO_voidGoToAngle(angle--);
			
				DST=ultra_getdist();
				if (DST<4 || DST > 400 )DST=0; 
				itoa(angle,(char*)angle_str,10);
				itoa(DST,(char*)dst_str,10);
				strcat((char*)dst_str, " "); strcat((char*)dst_str,angle_str);
				UART_voidTransmitString(dst_str,UART0);
		
			
				UART_voidTransmitByte('\n',UART0) ;
			
			//	ultra_getangle(angle);
				_delay_ms(14);
		}
	}
}


/*
while(1){
	ultra_triger();
	HSERVO_voidGoToAngle(100);
	_delay_ms(500);
	ultra_triger();
	HSERVO_voidGoToAngle(150);
	_delay_ms(500);
}*/