.PHONY:all clean
# scan current directory sources files
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
BIN := $(addprefix $(BUILD_ROOT)/,$(BIN))

# link object files directory
LINK_OBJ_DIR = $(BUILD_ROOT)/app/link_obj
$(shell mkdir -p $(LINK_OBJ_DIR))
DEP_DIR = $(BUILD_ROOT)/app/dep
$(shell mkdir -p $(DEP_DIR))
# lib object files directory
LIB_OBJ_DIR = $(BUILD_ROOT)/app/lib_obj
$(shell mkdir -p $(LIB_OBJ_DIR))
LIB_DIR = $(BUILD_ROOT)/lib

OBJ_DIR = $(LINK_OBJ_DIR)
ifneq ("$(LIB)","")
OBJ_DIR = $(LIB_OBJ_DIR)
endif
ifneq ("$(DLL)","")
OBJ_DIR = $(LIB_OBJ_DIR)
# for dll object files param
PIC     = -fPIC
endif


OBJS := $(addprefix $(OBJ_DIR)/,$(OBJS))
DEPS := $(addprefix $(DEP_DIR)/,$(DEPS))
LIB  := $(addprefix $(LIB_DIR)/,$(LIB))
DLL  := $(addprefix $(LIB_DIR)/,$(DLL))

LINK_OBJ = $(wildcard $(LINK_OBJ_DIR)/*.o)
LINK_OBJ += $(OBJS)

LIB_DEP = $(wildcard $(LIB_DIR)/*.a) $(wildcard $(LIB_DIR)/*.so)
LIB_DEP += $(wildcard $(LIB_DIR)/ext_lib/*.a) $(wildcard $(LIB_DIR)/ext_lib/*.so)
LINK_LIB_NAME = $(patsubst lib%,-l%,$(basename $(notdir $(LIB_DEP))))

all: $(DEPS) $(OBJS) $(LIB) $(DLL) $(BIN)
ifneq ("$(wildcard $(DEPS))","")	
include $(DEPS)
endif
$(BIN):$(LINK_OBJ)
	gcc -o $@ $^ -L$(LIB_DIR) -L$(LIB_DIR)/ext_lib $(LINK_LIB_NAME)
$(LIB):$(OBJS)
	ar rcs $@ $^
$(DLL):$(OBJS)
	gcc -shared -o $@ $^
$(OBJ_DIR)/%.o:%.c
	gcc -I$(HEAD_PATH) -o $@ -c $(PIC) $(filter %.c,$^)
$(DEP_DIR)/%.d:%.c
	gcc -I$(HEAD_PATH) -MM $(filter %.c,$^) | sed 's,\(.*\)\.o[ :]*,$(OBJ_DIR)/\1.o $@:,g' > $@
clean:
	rm -f  $(BIN) $(OBJS) $(DEPS)
