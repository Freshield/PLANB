/*
 * PLANB_TIMER.cpp
 *
 * Created: 2015/9/23 19:34:45
 *  Author: FRESHIELD
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <C:\Users\FRESHIELD\Documents\MEGAsync\EDEN\avr\system\lib_delay.h>
#include <C:\Users\FRESHIELD\Documents\MEGAsync\EDEN\avr\function\lib_pwm_m16.h>
#include <C:\Users\FRESHIELD\Documents\MEGAsync\EDEN\avr\device\lib_led.h>

int count = 1;

ISR(TIMER1_COMPA_vect)
{ 
	    
		LED_PORT = ~ LED_PORT;   

	
}    
  
  
int main(void)   
{
	LED_INIT();     
	 
	TIMER1_CTC_OCR1A_INIT();
	TIMER1_CTC_OCR1A_set(1);
	sei();
	
    while(1)
    {
        
    }
}
