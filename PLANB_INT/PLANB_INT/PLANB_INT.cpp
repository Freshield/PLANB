/*
 * PLANB_INT.cpp
 *
 * Created: 2015/9/23 16:59:58
 *  Author: FRESHIELD
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <C:\Users\FRESHIELD\Documents\MEGAsync\EDEN\avr\system\lib_delay.h>
#include <C:\Users\FRESHIELD\Documents\MEGAsync\EDEN\avr\system\lib_external_interrupt_m16.h>
#include <C:\Users\FRESHIELD\Documents\MEGAsync\EDEN\avr\device\lib_led.h>
#include <C:\Users\FRESHIELD\Documents\MEGAsync\EDEN\avr\device\lib_keyboard.h>


ISR(INT0_vect)
{
	KEY_INT_M16();  
}  

int main(void) 
{ 
	LED_INIT();   
	   
	EXTERNAL_INTERRUPT0_INIT_M16();
	
	sei();
	 
	 
    while(1)
    {
		
		delay_reduce(10);
    }
}