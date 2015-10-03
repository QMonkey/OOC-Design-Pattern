EXECPATH = ../bin
OBJPATH = ../obj
INCLUDEPATH = include
LIBPATH = ../lib/include
SRCPATH = src
CC = gcc
OPTIONS = -fms-extensions

EXEC = $(EXECPATH)/Decorator
OBJS = $(OBJPATH)/window.o $(OBJPATH)/border_decorator.o $(OBJPATH)/Decorator_main.o

all: $(OBJS) $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -g -o $@ $(OBJS)

$(OBJPATH)/window.o: $(SRCPATH)/window.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/border_decorator.o: $(SRCPATH)/border_decorator.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/Decorator_main.o: $(SRCPATH)/main.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

clean:
	-rm -rf $(EXEC) $(OBJS)
