/*
 * PLANB_USART_RECEIVE.cpp
 *
 * Created: 2015/10/7 22:14:51
 *  Author: FRESHIELD
 */ 


#include <avr/io.h>
#include <avr/interrupt.h>
#include <C:\Users\FRESHIELD\Documents\MEGAsync\EDEN\avr\system\lib_delay.h>
#include <C:\Users\FRESHIELD\Documents\MEGAsync\EDEN\avr\device\lib_lcd1602_m16.h>
#include <C:\Users\FRESHIELD\Documents\MEGAsync\EDEN\avr\function\lib_usart_m16.h>

//char read[17] ="                ";
static char read0[17];
static char read1[17];
char count = 0;
char line = 0;
char button = 0;

ISR(USART_TXC_vect)
{
	delay_reduce(1);
}
ISR(USART_UDRE_vect)
{
	delay_reduce(1);
}
ISR(USART_RXC_vect)
{
	
	
				if (line == 0)
				{
					read0[count] = UDR;
					
					read0[count+1] = '\0';\
					
					button = 1;
					
				}
				else 
				{
					
					read1[count] = UDR;
					 
					read1[count+1] = '\0';
					
					button = 1;
					
				}
				
				count ++;
			
	if (count >=16)
	{
		line ++;
		count = 0;
		if (line == 1)
		{
			for (char i = 0;i < 16;i ++)
			{
				read1[i] = 0x20;
			}
		}
		
		else if (line >= 2)
		{
			line = 0;
			for (char i = 0;i < 16;i ++)
			{
				read0[i] = 0x20;
			}
		}
		
	}
}

int main(void)
{
	
	M16_USART_READ_INIT();
	
	M16_USART_SEND_INIT();
	 
	LCD_init();
	
	 LCD_SHOW_STRING(0,0,"WAITING THE DATA") ;
	 
	 sei();
	
    while(1)
    {
		switch (button)
		{
			case 0: delay_reduce(10);
			
			break;
			
			case 1: 
			
			LCD_CLEAR();
			
			//LCD_SHOW_STRING(0,0,read0);
			
			LCD_SHOW_STRING(0,0,"NO WAY");
			//LCD_SHOW_STRING(0,1,read1);
			LCD_SHOW_STRING(0,1,"NO WAY");
			if (line == 0)
			{
				
				//M16_USART_SEND_STRING(read0,1,1);
				
				M16_USART_SEND_STRING("NO WAY",1,1);
				
				
			}
			else
			{
				
				//M16_USART_SEND_STRING(read1,1,1);
				
				M16_USART_SEND_STRING("NO WAY",1,1);
				
				
			}
			
			button = 0;
			
			break;
			
			default: button = 0;
			
			break;
			
			
		}
    }
}