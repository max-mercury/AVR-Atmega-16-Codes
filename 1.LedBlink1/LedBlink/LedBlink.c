
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC = 0b00000001;
    while(1)
    {
		PORTC = 0b00000001;
		_delay_ms(100);
		PORTC = 0b00000000;
		_delay_ms(100); 
    }
}