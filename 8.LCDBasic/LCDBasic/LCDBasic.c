
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"

int main(void)
{
	lcd_init(LCD_DISP_ON);
	int i = 0;
	char buffer[10];
    while(1)
    {
        lcd_clrscr();
        lcd_gotoxy(0,0);
        lcd_puts("hello");
        lcd_gotoxy(6,0);
		lcd_puts("world");
		//to print a variable
		//itoa(i,buffer,10);
		//lcd_puts(buffer);
		//i++;
		_delay_ms(1000);
    }
}