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
#include <D:\MEGA\EDEN\avr\device\lib_IR_m16.h>
#include <D:\MEGA\EDEN\avr\system\lib_basic.h>

uchar flow = 0;

uchar model = 0;//figure out the up or down edge
uchar figure = 0;
uchar time = 0;
uchar lister = 0;
unsigned int old_num = 0;
unsigned int new_num,change_num;
char buffer[30];
uchar count = 0;


void IR_receiver_catch()
{
	new_num = ICR1;
	change_num = new_num - old_num;
	old_num = new_num;
}

ISR(TIMER1_CAPT_vect)
{
	IR_receiver_catch();
	
	model = IR_receiver_model_change(model);
	figure = 1;
}


 

int main(void)
{
    LED_INIT();
    
    LED_PORT = 0x00;
    
    M16_USART_SEND_INIT();
    
   IR_receiver_init(0);
    
    sei(); 
    
    while(1)
    {
		
	     if (figure == 0)
	     { 
		     delay_reduce(1);
	     }
	     else
	     {
		     
		     figure = 0;
		     lister++;
		     time = change_num/28.8;
		     buffer[count] = time;
		     count ++;
		     
	     }
	     if (lister >= 12)
	     {
			 buffer[count] = '\0';
		     for (int i = 1;buffer[i] != '\0';i++ )
		     {
				 delay_second(25);
				 LED_PORT = buffer[i];
				 BASIC_HexToDciAsWord(buffer[i]);
				 M16_USART_SEND_ALONE(BASIC_hun);
				 M16_USART_SEND_ALONE(BASIC_ten);
				 M16_USART_SEND_ALONE(BASIC_poi);
				 M16_USART_SEND_ALONE('\r');
				 M16_USART_SEND_ALONE('\n');
				 
		     }
				 
	     }
	}
}

