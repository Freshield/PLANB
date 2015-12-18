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
	     if (lister >= 6)
	     {
			 
		     
				 
		     delay_second(25);
		     LED_PORT = buffer[1]; 
			  char hun = buffer[1]/100;
		     hun = hun + '0';
		      char ten = buffer[1]%100/10;
		     ten = ten + '0';
		     char poi = buffer[1]%10;
		     poi = poi + '0';
		     M16_USART_SEND_ALONE(hun); 
		     M16_USART_SEND_ALONE(ten);
		     M16_USART_SEND_ALONE(poi);
		     M16_USART_SEND_ALONE('\r');
		     M16_USART_SEND_ALONE('\n');
		     delay_second(25);
		     LED_PORT = buffer[2];
			   hun = buffer[2]/100;
			  hun = hun + '0';
			   ten = buffer[2]%100/10;
			  ten = ten + '0';
			   poi = buffer[2]%10;
			  poi = poi + '0';
			  M16_USART_SEND_ALONE(hun);
			  M16_USART_SEND_ALONE(ten);
			  M16_USART_SEND_ALONE(poi);
			  M16_USART_SEND_ALONE('\r');
			  M16_USART_SEND_ALONE('\n');
		     delay_second(25);
		     LED_PORT = buffer[3];
		     hun = buffer[3]/100;
		     hun = hun + '0';
		     ten = buffer[3]%100/10;
		     ten = ten + '0';
		     poi = buffer[3]%10;
		     poi = poi + '0';
		     M16_USART_SEND_ALONE(hun);
		     M16_USART_SEND_ALONE(ten);
		     M16_USART_SEND_ALONE(poi);
		     M16_USART_SEND_ALONE('\r');
		     M16_USART_SEND_ALONE('\n');
		     delay_second(25);
		     LED_PORT = buffer[4];
			 hun = buffer[4]/100;
			 hun = hun + '0';
			 ten = buffer[4]%100/10;
			 ten = ten + '0';
			 poi = buffer[4]%10;
			 poi = poi + '0';
			 M16_USART_SEND_ALONE(hun);
			 M16_USART_SEND_ALONE(ten);
			 M16_USART_SEND_ALONE(poi);
			 M16_USART_SEND_ALONE('\r');
			 M16_USART_SEND_ALONE('\n');
		     delay_second(25);
		     LED_PORT = buffer[5];
			 hun = buffer[5]/100;
			 hun = hun + '0';
			 ten = buffer[5]%100/10;
			 ten = ten + '0';
			 poi = buffer[5]%10;
			 poi = poi + '0';
			 M16_USART_SEND_ALONE(hun);
			 M16_USART_SEND_ALONE(ten);
			 M16_USART_SEND_ALONE(poi);
			 M16_USART_SEND_ALONE('\r');
			 M16_USART_SEND_ALONE('\n');
		     delay_second(25);
		     LED_PORT = buffer[6];
			 hun = buffer[6]/100;
			 hun = hun + '0';
			 ten = buffer[6]%100/10;
			 ten = ten + '0';
			 poi = buffer[6]%10;
			 poi = poi + '0';
			 M16_USART_SEND_ALONE(hun);
			 M16_USART_SEND_ALONE(ten);
			 M16_USART_SEND_ALONE(poi);
			 M16_USART_SEND_ALONE('\r');
			 M16_USART_SEND_ALONE('\n');
		     delay_second(25);
		     LED_PORT = buffer[7];
			 hun = buffer[7]/100;
			 hun = hun + '0';
			 ten = buffer[7]%100/10;
			 ten = ten + '0';
			 poi = buffer[7]%10;
			 poi = poi + '0';
			 M16_USART_SEND_ALONE(hun);
			 M16_USART_SEND_ALONE(ten);
			 M16_USART_SEND_ALONE(poi);
			 M16_USART_SEND_ALONE('\r');
			 M16_USART_SEND_ALONE('\n');
		     
	     }
	}
}

