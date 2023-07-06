#include<stdio.h>
#include "lcd.h"
#include "usb.h"
#include "media.h"
int main()
{
	printf("MP3 player init...\n");
	lcd_init();
	usb_init();
	media_init();
	return 0;
}
