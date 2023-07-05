.PHONY:all clean
export BUILD_ROOT = $(shell pwd)
export HEAD_PATH = $(BUILD_ROOT)/inc
all:
	make -C lcd
	make -C usb
	make -C media
	make -C math
	make -C app

clean:
	rm -rf app/link_obj app/dep app/lib_obj mp3
	rm -rf lib/*.a
	rm -rf lib/*.so
isntall:
	cp mp3 /usr/bin
	cp lib/libmath.so /usr/lib
	cp lib/ext_lib/librmvb.so /usr/lib
uninstall:
	rm /usr/bin/mp3
	rm /usr/lib/libmath.so
	rm /usr/lib/librmvb.so
