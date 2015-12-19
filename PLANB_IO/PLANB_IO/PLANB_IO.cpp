/*
 * PLANB_IO.cpp
 *
 * Created: 2015/9/23 16:25:02
 *  Author: FRESHIELD
 */    
   
  
#include <avr/io.h>  
#include <C:\Users\FRESHIELD\Documents\MEGAsync\EDEN\avr\system\lib_delay.h>
#include <C:\Users\FRESHIELD\Documents\MEGAsync\EDEN\avr\device\lib_led.h>
   
    
int main(void)     
{        
	LED_INIT();         
	
	LED_PORT = 0X01;
	 
    while(1)
    {
		delay_second(5);
      // LED_LEFT_CIRCLE(); 
    }
}