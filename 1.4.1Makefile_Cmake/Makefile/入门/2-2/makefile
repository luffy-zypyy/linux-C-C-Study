###############################
# a simple Makefile demo
# Author: wit.wang@qq.com
# Date:   2016.12.14
##############################
.PONHY:all clean
ifeq ($(DEBUG),"true")
CC = gcc -g
else
CC = gcc
endif
all:test1
all:test2
test1 :
	@echo "Just for test1:$@"
test2:
	@echo "Just for test2"

hello:lcd.o player.o
	@echo "start build hello"
	$(CC) -o hello lcd.o player.o
	@echo "build hello sucess"
#%.o:%.c
#	$(CC) -o $@ -c $^

clean:
	rm -f lcd.o hello player.o
