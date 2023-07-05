#include<stdio.h>
#include "lcd.h"
#include "media.h"

int main()
{
	printf("mp3 power on...\n");
	lcd_init();
	media_init();
	return 0;
}
