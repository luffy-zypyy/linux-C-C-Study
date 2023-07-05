.PHONY:clean
OBJS = player.o lcd.o
BIN  = mp3
$(BIN):$(OBJS)
	@echo "BIN------------$@:$^"
	gcc -o $@ $^ 
player.o:player.c
	@echo "------------$@:$^"
	gcc -o $@ -c $^
lcd.o:lcd.c
	@echo "---------$@:$^"
	gcc -o $@ -c $^
clean:
	rm -f $(BIN) $(OBJS)
