/*
 * IR_sender.cpp
 *
 * Created: 2015/10/2 15:30:41
 *  Author: FRESHIELD
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <D:\MEGA\EDEN\avr\system\lib_delay.h>
#include <D:\MEGA\EDEN\avr\function\lib_pwm_m16.h>
#include <D:\MEGA\EDEN\avr\device\lib_IR_m16.h>
#include <D:\MEGA\EDEN\avr\system\lib_external_interrupt_m16.h>
#include <D:\MEGA\EDEN\avr\device\lib_keyboard.h>

uchar statue = 0;
uchar time_lock = 0;
uchar key_lock = 0;

ISR(TIMER0_COMP_vect)
{
	
}

ISR(TIMER0_OVF_vect)
{
	
	IR_sender_service();
	
	
}

ISR(TIMER1_OVF_vect)
{
	time_lock = 1;
}

ISR(INT0_vect)
{
	
	if (KEY_INT_M16() == 0)
	{
		if (statue == 0)
		{ 
			key_lock = 1;
		}
		else
		{
			key_lock = 0;
		}
	}
}

int main(void)
{
	
	IR_sender_init();
	
	IR_sender_work();
	
	TIMER1_NORMAL_PWM_MS_INIT();
	
	TIMER1_NORMAL_PWM_MS_CLOSE();
	
	EXTERNAL_INTERRUPT0_INIT_M16();
	
	IR_sender_close();
	
	sei();
	
	/* Replace with your application code */
	while (1)
	{
		
		switch(statue)
		{
			case 0://wait key
			
			//IR_sender_zero();
			IR_sender_close();
			TIMER1_NORMAL_PWM_MS_CLOSE();
			EXTERNAL_INTERRUPT0_OPEN_M16();
			
			while(key_lock == 0)
			{
				delay_reduce(1);
			}
			key_lock = 0;
			EXTERNAL_INTERRUPT0_CLOSE_M16();
			statue = 6;
			
			break;
			
			case 1://5ms send
			//IR_sender_work();
			TIMER1_NORMAL_PWM_737MS1_set(5);
			IR_sender_open();
			TIMER1_NORMAL_PWM_MS_OPEN();
			while(time_lock == 0)
			{
				delay_reduce(1);
			}//wait timer1
			time_lock = 0;
			TIMER1_NORMAL_PWM_MS_CLOSE();
			statue = 2;
			break;
			
			case 2://10ms down
			//IR_sender_zero();
			TIMER1_NORMAL_PWM_737MS1_set(10);
			IR_sender_close();
			TIMER1_NORMAL_PWM_MS_OPEN();
			while(time_lock == 0)
			{
				delay_reduce(1);
			}//wait timer1
			time_lock = 0;
			TIMER1_NORMAL_PWM_MS_CLOSE();
			statue = 3;
			break;
			
			case 3://25ms send
			//IR_sender_work();
			TIMER1_NORMAL_PWM_737MS1_set(25);
			IR_sender_open();
			TIMER1_NORMAL_PWM_MS_OPEN();
			while(time_lock == 0)
			{
				delay_reduce(1);
			}//wait timer1
			time_lock = 0;
			TIMER1_NORMAL_PWM_MS_CLOSE();
			statue = 4;
			break;
			
			case 4://32ms down
			//IR_sender_zero();
			TIMER1_NORMAL_PWM_737MS1_set(32);
			IR_sender_close();
			TIMER1_NORMAL_PWM_MS_OPEN();
			while(time_lock == 0)
			{
				delay_reduce(1);
			}//wait timer1
			time_lock = 0;
			TIMER1_NORMAL_PWM_MS_CLOSE();
			statue = 5;
			break;
			
			case 5://5ms send
			//IR_sender_work();
			TIMER1_NORMAL_PWM_737MS1_set(5);
			IR_sender_open();
			TIMER1_NORMAL_PWM_MS_OPEN();
			while(time_lock == 0)
			{
				delay_reduce(1);
			}//wait timer1
			time_lock = 0;
			TIMER1_NORMAL_PWM_MS_CLOSE();
			statue = 0;
			break;
			
			case 6://avoid first error
			//IR_sender_zero();
			TIMER1_NORMAL_PWM_737MS1_set(1);
			IR_sender_close();
			TIMER1_NORMAL_PWM_MS_OPEN();
			while(time_lock == 0)
			{
				delay_reduce(1);
			}//wait timer1
			time_lock = 0;
			TIMER1_NORMAL_PWM_MS_CLOSE();
			statue = 1;
			break;
		}
		
		
		
	}
}

