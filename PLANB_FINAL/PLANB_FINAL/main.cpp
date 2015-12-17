/*
 * PLANB_FINAL.cpp
 *
 * Created: 2015/12/16 21:28:51
 * Author : FRESHIELD
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <D:\MEGA\EDEN\avr\system\lib_delay.h>
#include <D:\MEGA\EDEN\avr\device\lib_led.h>
#include <D:\MEGA\EDEN\avr\function\lib_usart_m16.h>

uchar flow = 0;


int main(void)
{
    LED_INIT(); 
    
    M16_USART_SEND_INIT();
    
    while(1)
    {
	    
	    switch (flow)
	    {
		    case 0: M16_USART_SEND_STRING("I LOVE YOU",1,1);
		    
		    LED_PORT = 0XFF;
		    delay_second(4);
		    LED_PORT = 0x00;
		    delay_second(4);
		    flow = 1;
		    break;
		    
		    case 1: M16_USART_SEND_STRING("OF COURSE I LOVE YOU",1,1);
		    
		    LED_PORT = 0XFF;
		    delay_second(4);
		    LED_PORT = 0x00;
		    delay_second(4);
		    flow = 2;
		    break;
		    
		    case 2: M16_USART_SEND_STRING("I PROMISE I LOVE YOU",1,1);
		    
		    LED_PORT = 0XFF;
		    delay_second(4);
		    LED_PORT = 0x00;
		    delay_second(4);
		    flow = 3;
		    break;
		    
		    
		    case 3: M16_USART_SEND_STRING("YOU ARE DEFINITELY MY PRINCESS",1,1);
		    
		    LED_PORT = 0XFF;
		    delay_second(4);
		    LED_PORT = 0x00;
		    delay_second(4);
		    flow = 4;
		    break;
		    
		    
		    case 4: M16_USART_SEND_STRING("MUA LOVE YOU FOREVER",1,1);
		    
		    LED_PORT = 0XFF;
		    delay_second(4);
		    LED_PORT = 0x00;
		    delay_second(4);
		    flow = 5;
		    break;
		    
		    
		    case 5: M16_USART_SEND_STRING("I MISS YOU EVERYDAY",1,1);
		    
		    LED_PORT = 0XFF;
		    delay_second(4);
		    LED_PORT = 0x00;
		    delay_second(4);
		    flow = 0;
		    break;
		    
		    default: M16_USART_SEND_STRING("ERROR APPEAR",1,1);
		    
		    LED_PORT = 0XFF;
		    delay_second(1);
		    LED_PORT = 0X00;
		    delay_second(1);
		    LED_PORT = 0XFF;
		    delay_second(1);
		    LED_PORT = 0X00;
		    delay_second(1);
		    flow = 0;
		    break;
		    
	    }
	}
}

