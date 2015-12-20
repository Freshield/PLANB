/*
 * PLANB_LCD1602.cpp
 *
 * Created: 2015/10/6 19:48:18
 *  Author: FRESHIELD
 */ 

#include <avr/io.h>
#include <D:\MEGA\EDEN\avr\system\lib_delay.h>
#include <D:\MEGA\EDEN\avr\device\lib_lcd1602_m16.h>

int main(void)
{
	LCD_init(); 
	
	char line1[] = {0X2E,0X2E,0X2E,0XA7,0XC5,0XC0,0X2E,0X2E,0X2E,0x20,0x20,0x20,0x20,0x20,0x20,0x20};
	char line2[] = {0XBD,0X2E,0X2E,0X2E,0XB7,0X2E,0X2E,0X2E,0x20,0x20,0x20,0x20,0x20,0x20,0x20,0x20};
	
    while(1)
    {
        LCD_SAMPLE_SHOW_STRING(0,0,line1);
		LCD_SAMPLE_SHOW_STRING(0,1,line2);
    }
}