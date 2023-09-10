#include "ultrasonic.h"
#include "../lCD/LCD.h"
#include "../../MCAL/UART/UART_interface.h"

uint8_t sensor_working=0;
uint8_t rising_edge=0;
uint32_t timer_counter=0;
uint32_t distance = 4;
uint8_t distance_str[10];
uint32_t Angle=0;
uint8_t Angle_str[10];

// UART_t UART0 ; 

void ultra_getangle(int Angle_Copy){Angle = Angle_Copy ;}
	
uint32_t ultra_getdist(void){
	if (distance > 400 || distance < 4) return ;
	 return distance ; 
	 }

void ultrasonic_init(void){

	//UART0 = UART_UART_tInit(UART_Tx_or_Rx, UART_Async_NormalSpeed, UART_Single, UART_InterruptDisable, UART_8bitData,
	//UART_PArityDisable_1Stop, UART_RisingEdge, 4800);
	
  TRIGER_DDR|=(1<<TRIGER);
  ECHO_DDR&=~(1<<ECHO);
  ECHO_PULLUP|=(1<<ECHO);
  enable_ex_interrupt();
  timer0_init();
  return;
}

void enable_ex_interrupt(void){

  MCUCR |= (1<<ISC10);		// Trigger INT1 on any logic change.
  GICR  |= (1<<INT1);			// Enable INT1 interrupts.

  return;
}

void ultra_triger(void){
  if(!sensor_working){
    TRIGER_PORT|=(1<<TRIGER);
    _delay_us(15);
    TRIGER_PORT&=~(1<<TRIGER);
    sensor_working=1;
  }
}

ISR(INT1_vect){
  if(sensor_working==1){
    if(rising_edge==0){
      TCNT0=0x00;
      rising_edge=1;
      timer_counter=0;
    }
  else{
    distance=(timer_counter*256+TCNT0)/58;
	if (distance > 400 || distance < 4) { //uint8_t message [22]= "Distance out of range" ; UART_voidTransmitString(message,UART0); 
	distance = 0 ;   }
    //lcd_goto_xy(1,0);
  	//itoa(distance,(char*)distance_str,10);
     	//strcat((char*)distance_str, " cm ");
  	//lcd_write_word(distance_str);
	 //
	 //
    //itoa(Angle,(char*)Angle_str,10);
	 //strcat((char*)Angle_str, " degrees ");
	//lcd_write_word(Angle_str);
	//
	//
//
	//UART_voidTransmitString(Angle_str, UART0);
	////UART_voidTransmitByte(',', UART0);
	//
			//UART_voidTransmitByte('\n',UART0) ;
			//UART_voidTransmitByte('\r',UART0) ;
	//
	//
	//UART_voidTransmitString(distance_str, UART0);
	////UART_voidTransmitByte('.', UART0);
	//
			//UART_voidTransmitByte('\n',UART0) ;
			//UART_voidTransmitByte('\r',UART0) ;
			//
					//UART_voidTransmitByte('\n',UART0) ;
					//UART_voidTransmitByte('\r',UART0) ;
					//UART_voidTransmitByte('\n',UART0) ;
					// UART_voidTransmitByte('\r',UART0) ;
	
		//UART_voidTransmitByte('\n',UART0) ;
		//UART_voidTransmitByte('\r',UART0) ;
	
	
		//UART_voidTransmitByte('\n',UART0) ;
		//UART_voidTransmitByte('\r',UART0) ;
	
    timer_counter=0;
    rising_edge=0;
  }
}}

ISR(TIMER0_OVF_vect){
    timer_counter++;
    if(timer_counter >730){
      TCNT0=0x00;
      sensor_working=0;
      rising_edge=0;
      timer_counter=0;
    }
}
