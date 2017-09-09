#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

double dutyCycle = 0;
char buffer[10];
int main(void)
{
	DDRB = (1 << PINB3);
	
	TCCR0 = (1 << WGM00) | (1 << WGM01) | (1 << COM01) | (1<<CS00); //| (1<<CS02);//prescaler of 1024 just for fast increase
	TIMSK = (1 << TOIE0);
	
	OCR0 = (dutyCycle/100.0)*255.0;
	
	sei();
	
	while(1)
	{
		_delay_ms(100);
		dutyCycle += 10;
		
		if(dutyCycle > 100)
		{
			dutyCycle = 0;
		}
	}
}

ISR(TIMER0_OVF_vect)
{
	OCR0 = (dutyCycle/100.0)*255;
}