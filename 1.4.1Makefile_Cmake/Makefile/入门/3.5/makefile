.PHONY:all clean
export BUILD_ROOT = $(shell pwd)
all:
	make -C lcd
	make -C usb
	make -C media
	make -C app

clean:
	rm -rf app/link_obj app/dep mp3
