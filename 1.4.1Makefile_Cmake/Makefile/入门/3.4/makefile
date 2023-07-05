.PHONY:all clean

all:
	make -C lcd
	make -C usb
	make -C media
	make -C app

clean:
	rm -f  mp3
	rm -fr app/link_obj/*.o app/player.d
	rm -fr usb/usb.o usb/usb.d
	rm -fr lcd/lcd.o lcd/lcd.d
	rm -fr media/media.o media/media.d
	rm -rf app/link_obj
