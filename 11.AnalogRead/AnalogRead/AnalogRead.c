#include <avr/io.h>
#include "lcd.h"
#include "ADC.h"
int main(void)
{
	lcd_init(LCD_DISP_ON);
	setup_adc();
	uint16_t result;
	char buffer[10];

	while(1)
	{
		result = input_adc (0);
		itoa(result, buffer, 10);
		lcd_gotoxy(0,0);
		lcd_puts(buffer);
	}
}