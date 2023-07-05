.PHONY: clean

test1 test2:
	@echo "test:"

hello:player.o lcd.o media.o
	gcc -o  $@ $^
%.o:%.c
	gcc -o $@ -c $^
clean:
	rm *.o hello
