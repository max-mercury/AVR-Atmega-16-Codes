#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

void main()
{
	DDRC |= (1 << PINC0);//Led pin as output
	DDRD &= ~(1 << PIND0);//button input
	PORTD |= (1 << PIND0);//set input high
	
	while(1)
	{
		PORTC ^= (1 << PINC0);
		
		if(bit_is_clear(PIND,0))
		{
			_delay_ms(10);
		}
		else
		{
			_delay_ms(1000);
		}
	}
}