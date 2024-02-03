/*
 * Gehad_Ahmed.c
 *
 * Created: 11/6/2023 12:52:11 PM
 *  Author: Dell
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "keypad_driver.h"
#include "LCD.h"
#include "ADC.h"
#include <math.h>
#include <stdio.h>
int main(void)
{
   ADC_Init();
   LCD_vInit();
   keypad_vInit();
   
   short ChangeTemp = 0, unitTemp, negTemp = 0;
   while (1)
   {
	   if(keypad_u8check_press() == 'A'){
		   ChangeTemp = 0;
		   LCD_clearscreen();
		   LCD_vSend_cmd(0x0C);
	   }
	   if(ChangeTemp == 0){
		   LCD_vSend_string("Choose the unit"); // Choose the unit of temperature measurement
		   LCD_movecursor(2, 1);
		   LCD_vSend_string("of measurement ?");
		   _delay_ms(4000);
		   LCD_clearscreen();
		   LCD_vSend_string("1) Celsius ");
		   LCD_movecursor(1, 12);
		   LCD_vSend_char(0xDF);
		   LCD_vSend_char('C');
		   LCD_movecursor(2, 1);
		   LCD_vSend_string("2) Fahrenheit ");
		   LCD_movecursor(2, 15);
		   LCD_vSend_char(0xDF);
		   LCD_vSend_char('F');
		   unitTemp = keypad_u8check_press();
		   while(unitTemp != '1' && unitTemp != '2')unitTemp = keypad_u8check_press();
		   ChangeTemp = 1;  
		   LCD_clearscreen();
		   LCD_vSend_string("Temperature ");
		   LCD_movecursor(2, 1);
		   LCD_vSend_string("actual= ");
       }
   
       double Volt = 0.25 * ADC_u32Read();  // Determine the voltage
       double Temp = Volt;
       LCD_movecursor(2, 8);
       double Celsius = Temp;
       
       if(unitTemp == '2'){
	       double Fahrenheit = 1.8 * Celsius + 32;
	       Temp = Fahrenheit;
       }
       else {
	       if(negTemp == 1){
		       LCD_vSend_char('-');
	       }
       }
	   char tempres[6];
	   LCD_sendFloat(Temp, tempres, 2);
	   LCD_vSend_string(tempres);
       LCD_movecursor(2, 14);
       LCD_vSend_char(0xDF);
       if(unitTemp == '2'){
	       LCD_vSend_char(0x46);
       }
       else {
	       LCD_vSend_char(0x43);
       }
	    _delay_ms(1000);
       
   }   
      
}
