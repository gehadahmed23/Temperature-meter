/*
 * ADC.c
 *
 * Created: 1/29/2024 10:03:20 PM
 *  Author: Dell
 */ 
#include "ADC.h"

 void ADC_Init(){
	SET_BIT(ADMUX, REFS0); // Selected internal voltage 
	SET_BIT(ADMUX, REFS1);
	
//	SET_BIT(ADMUX, MUX4); 
	
	SET_BIT(ADCSRA, ADEN); // enable ADC
	
	/* ADC clock 128 */
	SET_BIT(ADCSRA, ADPS1);
	SET_BIT(ADCSRA, ADPS2);
}

unsigned int ADC_u32Read(){
	unsigned int read_value;
	
	SET_BIT(ADCSRA, ADSC);
	while(IS_BIT_CLR(ADCSRA,ADIF));
	SET_BIT(ADCSRA,ADIF);
	read_value = ADCL;
	read_value |= (ADCH << 8);
	
	return read_value;
}