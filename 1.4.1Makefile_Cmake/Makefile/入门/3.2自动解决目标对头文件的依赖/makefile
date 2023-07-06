.PHONY:all clean
#自动解决目标对头文件的依赖
SRCS = $(wildcard *.c) #SRCS变量中存放的是当前目录下所有的.c文件
OBJS = $(SRCS:.c=.o) #变量替换，将当前目录下所有.c文件替换为.o文件并保存在OBJS变量中
DEPS = $(SRCS:.c=.d) #变量替换，将当前目录下所有.c文件替换为.d文件并保存在DEPS变量中
BIN  = mp3
all: $(BIN) $(DEPS) #这里需要加上$(DEPS)，否则%.d:%.c这个目标以及依赖就不在目标依赖树中了
ifneq ("$(wildcard $(DEPS))","") #如果.d文件存在，就把.d文件包含进来
include $(DEPS)
endif
$(BIN):$(OBJS)
	gcc -o $@ $^
%.o:%.c	# .d文件中存放的a.o:a.c a.h与这里的属于相同目标的多个规则，它们会进行合并，又因为gcc -o a.o -c后面只能加上.c源文件，所以
	gcc -o $@ -c $(filter %.c,$^) 	#这里用filter函数从目标依赖中把.h文件过滤掉，只留下.c文件，保证编译不会出错
%.d:%.c
	gcc -MM $^ > $@ #根据.c文件生成其对应的目标以及依赖并重定向到.d文件中，.d文件中内容形如a.o:a.c a.h
clean:
	rm -f  $(BIN) $(OBJS) $(DEPS)
