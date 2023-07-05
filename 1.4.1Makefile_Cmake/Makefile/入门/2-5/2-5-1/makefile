.PHONY:all
SRCS = player.c lcd.c usb.c media.c hello.h main.txt
OBJS = $(subst .c,.o,$(strip $(SRCS)))
DEPS = $(patsubst %.c,%.d,$(SRCS))
DEPS2 = $(SRCS:.c=.d)
FIND = $(findstring usb,$(SRCS))
FILTER = $(filter %.c %.h, $(SRCS))
all:
	@echo "OBJS = $(OBJS)"	
	@echo "DEPS = $(DEPS)"
	@echo "DEPS2 = $(DEPS2)"
	@echo "FIND = $(FIND)"
	@echo "FILTER = $(FILTER)"
