/*
 * PLANB_PWM.cpp
 *
 * Created: 2015/9/24 22:43:54
 *  Author: FRESHIELD
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <C:\Users\FRESHIELD\Documents\MEGAsync\EDEN\avr\system\lib_delay.h>
#include <C:\Users\FRESHIELD\Documents\MEGAsync\EDEN\avr\function\lib_pwm_m16.h>
#include <C:\Users\FRESHIELD\Documents\MEGAsync\EDEN\avr\device\lib_led.h>

int model,pointer = 0;
uchar auc_SinParam[128] = {
	128,134,140,147,153,159,165,171,177,182,188,193,198,204,208,213,
	218,222,226,230,233,237,240,242,245,247,249,251,252,253,254,254,
	254,254,253,252,251,250,248,246,244,241,238,235,232,228,224,220,
	215,211,206,201,196,191,185,179,174,168,162,156,150,144,137,131,
	125,119,112,106,100,94,88,82,77,71,65,60,55,50,45,41,
	36,32,28,24,21,18,15,12,10,8,6,5,4,3,2,2,
	2,2,3,4,5,7,9,11,14,16,19,23,26,30,34,38,
43,48,52,57,63,68,74,79,85,91,97,103,109,116,122,128};  // 128点正弦波样本值


ISR(TIMER1_COMPA_vect)
{
	LED_PORT = 0X00;
}

ISR(TIMER1_OVF_vect)
{
	LED_PORT = 0XFF;
	
	
	
	OCR1A = auc_SinParam[pointer];  // 取样点指针到比较匹配寄存器
	pointer ++;      // 新样点指针
	if (pointer == 128)
	{
		pointer = 0;
	}
	
} 
 
int main(void)
{
	LED_INIT(); 
	
	TIMER1_FASTPWMA_ICR1_init();
	 
	TIMER1_FASTPWMA_ICR1_dutycircle_add(2,128);
	
	sei();
	
	LED_PORT = 0xFF;
	
    while(1)
    {
        //TODO:: Please write your application code 
    }
}