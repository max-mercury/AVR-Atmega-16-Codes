
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC = 0xff;
    while(1)
    {
        PORTC ^= 0xff;
		_delay_ms(100);
    }
}