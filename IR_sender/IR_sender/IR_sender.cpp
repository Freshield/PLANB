/*
 * IR_sender.cpp
 *
 * Created: 2015/10/2 15:30:41
 *  Author: FRESHIELD
 */  

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <D:\MEGA\EDEN\avr\system\lib_delay.h>
#include <D:\MEGA\EDEN\avr\function\lib_pwm_m16.h>
#include <D:\MEGA\EDEN\avr\device\lib_IR_m16.h>
#include <D:\MEGA\EDEN\avr\system\lib_external_interrupt_m16.h>
#include <D:\MEGA\EDEN\avr\device\lib_keyboard.h>

uchar statue = 0;
uchar time_lock = 0; 
uchar key_lock = 0;

float timelist[6] = {5.0,10.0,25.0,32.0,5.0,10.0};

 
ISR(TIMER0_OVF_vect)
{
	
}

ISR(TIMER1_COMPA_vect)
{
	TIMER1_CTC_PWM_MS_CLOSE();
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
	
	TIMER1_CTC_PWM_MS_INIT(); 
	
	TIMER1_CTC_PWM_MS_CLOSE();
	
	EXTERNAL_INTERRUPT0_INIT_M16();
	
	IR_sender_close();
	
	sei();
	
	/* Replace with your application code */
	while (1)
	{
		IR_sender_close();//down edge
		TIMER1_CTC_PWM_MS_CLOSE();//close
		EXTERNAL_INTERRUPT0_OPEN_M16();
		//TIMER1_CTC_PWM_737MS1_calculate(5);
		while(key_lock == 0)
		{
			delay_reduce(1);
		}
		key_lock = 0;
		EXTERNAL_INTERRUPT0_CLOSE_M16();
		
		PORTA = 0XFF;
		
		OCR1A = 738;
		IR_sender_open();//up edge  
		TIMER1_CTC_PWM_MS_OPEN();//open 
		//TIMER1_CTC_PWM_737MS1_calculate(10);
		while(time_lock == 0)
		{
			delay_reduce(1);
		}//wait timer1
		time_lock = 0; 
		PORTA = 0X00;
		
		TIMER1_CTC_PWM_MS_CLOSE();
		OCR1A = 3686;
		IR_sender_close();
		TIMER1_CTC_PWM_MS_OPEN();
		//TIMER1_CTC_PWM_737MS1_calculate(15);
		while(time_lock == 0)
		{ 
			delay_reduce(1);
		}//wait timer1
		time_lock = 0; 
		
		PORTA = 0XFF;
		
		TIMER1_CTC_PWM_MS_CLOSE();
		OCR1A = 18432;
		IR_sender_open();//up edge
		TIMER1_CTC_PWM_MS_OPEN();//open
		//TIMER1_CTC_PWM_MS_calculate(timelist[1]);
		while(time_lock == 0)
		{
			delay_reduce(1);
		}//wait timer1
		time_lock = 0;
		/*
		switch(statue)
		{
			case 0://wait key
			
			//IR_sender_zero();
			IR_sender_close();
			TIMER1_CTC_PWM_MS_CLOSE();
			EXTERNAL_INTERRUPT0_OPEN_M16();
			TIMER1_CTC_PWM_MS_calculate(timelist[0]);
			while(key_lock == 0)
			{
				delay_reduce(1);
			}
			key_lock = 0;
			EXTERNAL_INTERRUPT0_CLOSE_M16();
			statue = 1;
			
			break;
			
			case 1://5ms send
			//IR_sender_work();
			//TIMER1_NORMAL_PWM_737MS1_set(5);
			TCNT1 = helper;
			IR_sender_open();
			TIMER1_CTC_PWM_MS_OPEN();
			TIMER1_CTC_PWM_MS_calculate(timelist[1]);
			while(time_lock == 0)
			{
				delay_reduce(1);
			}//wait timer1
			time_lock = 0;
			statue = 2;
			break;
			
			case 2://10ms down
			//IR_sender_zero();
			//TIMER1_NORMAL_PWM_737MS1_set(10);
			TCNT1 = helper;
			IR_sender_close();
			TIMER1_CTC_PWM_MS_OPEN();
			TIMER1_CTC_PWM_MS_calculate(timelist[2]);
			while(time_lock == 0)
			{
				delay_reduce(1);
			}//wait timer1
			time_lock = 0; 
			statue = 3;
			break;
			
			case 3://25ms send
			//IR_sender_work();
			//TIMER1_NORMAL_PWM_737MS1_set(25);
			TCNT1 = helper;
			IR_sender_open();
			TIMER1_CTC_PWM_MS_OPEN();
			TIMER1_CTC_PWM_MS_calculate(timelist[3]);
			while(time_lock == 0)
			{
				delay_reduce(1);
			}//wait timer1
			time_lock = 0;
			statue = 4;
			break;
			
			case 4://32ms down
			//IR_sender_zero();
			//TIMER1_NORMAL_PWM_737MS1_set(32);
			TCNT1 = helper;
			IR_sender_close();
			TIMER1_CTC_PWM_MS_OPEN();
			TIMER1_CTC_PWM_MS_calculate(timelist[4]);
			while(time_lock == 0)
			{
				delay_reduce(1);
			}//wait timer1
			time_lock = 0;
			statue = 5;
			break;
			
			case 5://5ms send
			//IR_sender_work();
			//TIMER1_NORMAL_PWM_737MS1_set(5);
			TCNT1 = helper;
			IR_sender_open();
			TIMER1_CTC_PWM_MS_OPEN();
			TIMER1_CTC_PWM_MS_calculate(timelist[5]);
			while(time_lock == 0)
			{
				delay_reduce(1);
			}//wait timer1
			time_lock = 0;
			statue = 0;
			break;
			
		}
		*/
		
	}
}

