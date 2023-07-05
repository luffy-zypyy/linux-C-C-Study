#include<stdio.h>
#include "lcd.h"
#include "usb.h"
#include "media.h"
#include "math.h"
#include "jpg.h"
#include "rmvb.h"
int main()
{
	printf("MP3 player init...\n");
	lcd_init();
	usb_init();
	media_init();
	math_dll_init();
	jpg_init();
	rmvb_init();
	return 0;
}
