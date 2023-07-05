.PHONY:clean
N = 1
OBJS = player.o lcd.o
BIN  = mp3
$(BIN):$(OBJS)
	@echo "BIN:N=$(N)"
	gcc -o $(BIN) $(OBJS)
$(BIN): N = 2
%.o: N = 3
player.o:player.c
	@echo "player.o:N=$(N)"
	gcc -o player.o -c player.c
lcd.o:lcd.c
	@echo "lcd.o:N=$(N)"
	gcc -o lcd.o -c lcd.c
clean:
	@echo "clean: N = $(N)"
	rm  $(BIN) $(OBJS)
