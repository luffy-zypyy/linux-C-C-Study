.PHONY:all
LIB = /home/hello/libhello.a
LIB1 = $(dir $(LIB))
LIB2 = $(notdir $(LIB))
LIB3 = $(suffix $(LIB))
LIB4 = $(basename $(LIB))
LIB5 = $(addsuffix .c,$(LIB4))
LIB6 = $(addprefix /usr/lib/,$(LIB2))
SRCS = $(wildcard *.c)
all:
	@echo "LIB1 = $(LIB1)"
	@echo "LIB2 = $(LIB2)"
	@echo "LIB3 = $(LIB3)"
	@echo "LIB4 = $(LIB4)"
	@echo "LIB5 = $(LIB5)"
	@echo "LIB6 = $(LIB6)"	
	@echo "SRCS = $(SRCS)"
