.PHONY:all clean

SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
BIN := $(addprefix $(BUILD_ROOT)/,$(BIN))

LINK_OBJ_DIR = $(BUILD_ROOT)/app/link_obj
$(shell mkdir -p $(LINK_OBJ_DIR))
DEP_DIR = $(BUILD_ROOT)/app/dep
$(shell mkdir -p $(DEP_DIR))
LIB_OBJ_DIR = $(BUILD_ROOT)/app/lib_obj
$(shell mkdir -p $(LIB_OBJ_DIR))
LIB_DIR = $(BUILD_ROOT)/lib

OBJ_DIR = $(LINK_OBJ_DIR)
ifneq ("$(LIB)","")
OBJ_DIR = $(LIB_OBJ_DIR)
endif

OBJS := $(addprefix $(OBJ_DIR)/,$(OBJS))
DEPS := $(addprefix $(DEP_DIR)/,$(DEPS))
LIB  := $(addprefix $(LIB_DIR)/,$(LIB))

LINK_OBJ = $(wildcard $(LINK_OBJ_DIR)/*.o)
LINK_OBJ +=$(OBJS)

LIB_DEP = $(wildcard $(LIB_DIR)/*.a)
LINK_LIB_NAME = $(patsubst lib%,-l%,$(basename $(notdir $(LIB_DEP))))

all: $(DEPS) $(OBJS) $(LIB) $(BIN)
ifneq ("$(wildcard $(DEPS))","")	
include $(DEPS)
endif
$(BIN):$(LINK_OBJ) $(LIB_DEP)
	@echo "LINK_LIB_NAME=$(LINK_LIB_NAME)"
	gcc -o $@ $^ -L$(LIB_DIR) $(LINK_LIB_NAME)
$(LIB):$(OBJS)
	ar rcs $@ $^
$(OBJ_DIR)/%.o:%.c
	gcc -I$(HEAD_PATH) -o $@ -c $(filter %.c,$^)
$(DEP_DIR)/%.d:%.c
	gcc -I$(HEAD_PATH) -MM $(filter %.c,$^) | sed 's,\(.*\)\.o[ :]*,$(OBJ_DIR)/\1.o $@:,g' > $@
clean:
	rm -f  $(BIN) $(OBJS) $(DEPS)
