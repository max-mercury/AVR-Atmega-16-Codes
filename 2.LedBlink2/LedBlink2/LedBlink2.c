#include <avr/io.h>
#include <util/delay.h>

void main()
{
	DDRC |= (1 << PINC0);
	while(1)
	{
		PORTC ^= (1 << PINC0);
		_delay_ms(100);
	}
}