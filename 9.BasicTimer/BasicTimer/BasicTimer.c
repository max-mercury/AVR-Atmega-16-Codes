#define F_CPU 16000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

int extraTime = 0;

int main(void)
{
	DDRC |= (1<<PINC0);
	TCCR0 |= (1 << WGM01); //Set CTC Bit
	OCR0 = 15625;
	TIMSK = (1 << OCIE0);
	
	sei();
	
	TCCR0 |= (1 << CS00) | (1 << CS02); //start at 1024 prescalar
	
	while(1)
	{
		
	}
}

ISR(TIMER0_COMP_vect)
{
	extraTime++;
	
	if(extraTime > 100)
	{
		extraTime = 0;
		PORTC ^= (1 << PINC0);
	}
}

//http://eleccelerator.com/avr-timer-calculator/