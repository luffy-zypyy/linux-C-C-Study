.PHONY:all clean
export BUILD_ROOT = $(shell pwd)
export HEAD_PATH = $(BUILD_ROOT)/inc
all:
	make -C lcd
	make -C usb
	make -C media
	make -C app

clean:
	rm -rf app/link_obj app/dep mp3
