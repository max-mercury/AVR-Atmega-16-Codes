

#include <avr/io.h>


void setup_adc()
{
	ADMUX = (1<<REFS0); 
	ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0); 
}
uint16_t input_adc(uint8_t chnl)
{
	chnl &= 0b00000111;  
	ADMUX = (ADMUX & 0xF8)|chnl;
	ADCSRA |= (1<<ADSC);
	while(ADCSRA & (1<<ADSC));
	return (ADC);
}

