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

uchar flow = 0;

uchar model = 0;//figure out the up or down edge
uchar figure = 0;
uchar time = 0;
uchar lister = 0;
unsigned int old_num = 0;
unsigned int new_num,change_num;
char buffer[10];
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
    
    IR_receiver_init(0);
    
    //M16_USART_SEND_INIT();
    
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
	     if (lister >= 6)
	     {
		     delay_second(25);
		     LED_PORT = buffer[0];
		     delay_second(25);
		     LED_PORT = buffer[1];
		     delay_second(25);
		     LED_PORT = buffer[2];
		     delay_second(25);
		     LED_PORT = buffer[3];
		     delay_second(25);
		     LED_PORT = buffer[4];
		     delay_second(25);
		     LED_PORT = buffer[5];
		     delay_second(25);
		     LED_PORT = buffer[6];
		     delay_second(25);
		     LED_PORT = buffer[7];
		     
	     }
	}
}

