EXECPATH = ../bin
OBJPATH = ../obj/Adapter
INCLUDEPATH = include
LIBPATH = ../lib/include
SRCPATH = src
CC = gcc
OPTIONS = -fms-extensions

EXEC = $(EXECPATH)/Adapter
OBJS = $(OBJPATH)/target.o $(OBJPATH)/adaptee.o $(OBJPATH)/adapter.o $(OBJPATH)/Adapter_main.o

all: $(OBJS) $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -g -o $@ $(OBJS)

$(OBJPATH)/target.o: $(SRCPATH)/target.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/adaptee.o: $(SRCPATH)/adaptee.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/adapter.o: $(SRCPATH)/adapter.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/Adapter_main.o: $(SRCPATH)/main.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

clean:
	-rm -rf $(EXEC) $(OBJS)
