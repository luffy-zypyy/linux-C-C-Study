.PHONY:all clean

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
BIN  = mp3
all: $(BIN)

$(BIN):$(OBJS)
	@echo "SRCS =$(SRCS)"
	@echo "OBJS =$(OBJS)"
	gcc -o $@ $^
%.o:%.c
	gcc -o $@ -c $^
clean:
	rm -f  $(BIN) $(OBJS)
