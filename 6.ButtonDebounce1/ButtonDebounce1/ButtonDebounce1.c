#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

//Button Debouncing
void main()
{
	DDRC |= (1 << PINC0); //0 as output
	PORTC ^= (1<<PINC0);
	DDRC |= (1<< PINC2);  // 2 as output
	DDRD &= ~(1 << PIND0);//1 as input
	PORTD |= (1 << PIND0);//set high
	int pressed=0,pressed_conf_lvl=0,released_conf_level=0;
	while(1)
	{
		if(bit_is_clear(PIND,0))
		{
			pressed_conf_lvl++;
			released_conf_level=0;
			if(pressed_conf_lvl > 500)
			{
				if(pressed == 0)
				{
					PORTC ^= 1<< PINC0;
					PORTC ^= 1<< PINC2;
					pressed = 1;
				}
				pressed_conf_lvl=0;
			}
		}
		else
		{
			released_conf_level++;
			pressed_conf_lvl=0;
			if(released_conf_level > 500)
			{
				pressed = 0;
				released_conf_level=0;
			}
		}
	}
}