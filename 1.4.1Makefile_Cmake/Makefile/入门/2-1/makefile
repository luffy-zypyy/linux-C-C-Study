###############################
# a simple Makefile demo
# Author: wit.wang@qq.com
# Date:   2016.12.20
##############################
ifeq ($(DEBUG),"true")
CC = gcc -g
else
CC = gcc
endif
all:hello
hello:lcd.o player.o
	$(CC) -o hello lcd.o player.o
player.o:player.c
	$(CC) -o player.o -c player.c
lcd.o:lcd.c
	$(CC) -o lcd.o -c lcd.c
clean:
	rm lcd.o hello player.o
