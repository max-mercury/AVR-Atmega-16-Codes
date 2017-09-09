#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

//Two Leds Toggle
void main()
{
	DDRC |= (1 << PINC0); //Led at C0 as output
	PORTC ^= (1<<PINC0);
	DDRC |= (1<< PINC2);  //Led2 at C2 as output
	DDRD &= ~(1 << PIND1);//Button at D1 as input
	PORTD |= (1 << PIND1);//Set high
	int pressed=0;
	while(1)
	{
		if(bit_is_clear(PIND,0))
		{
			if(pressed == 0)
			{
				PORTC ^= 1<< PINC0;
				PORTC ^= 1<< PINC2;
				pressed = 1;
			}
		}
		else
		{
			pressed = 0;
		}
	}
}