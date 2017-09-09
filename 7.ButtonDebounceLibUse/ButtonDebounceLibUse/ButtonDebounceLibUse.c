#define numOfBtn 1

#include <avr/io.h>
#include <avr/interrupt.h>
#include "buttonlib.h"


void main()
{
	DDRD &=~ (1<<PIND0); 
	DDRC  |= (1<<PINC0);
	PORTD |= (1<<PIND0);
	while(1)
	{
		if(buttonPressed(0,PIND,0,500))
		{
			PORTC ^= (1<<PINC0);
		}
	}
}