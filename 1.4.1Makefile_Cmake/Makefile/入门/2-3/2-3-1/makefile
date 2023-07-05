.PHONY:clean

CC = gcc
BIN = hello
OBJS = player.o lcd.o
$(BIN): $(OBJS)
	$(CC) -o $(BIN) $(OBJS)

player.o:player.c
	$(CC) -o player.o -c player.c
lcd.o:lcd.c
	$(CC) -o lcd.o -c lcd.c
clean:
	rm -f player.o lcd.o hello
