EXECPATH = ../bin
OBJPATH = ../obj/Command
INCLUDEPATH = include
LIBPATH = ../lib/include
SRCPATH = src
CC = gcc
OPTIONS = -fms-extensions

EXEC = $(EXECPATH)/Command
OBJS = $(OBJPATH)/linkedlist.o $(OBJPATH)/linkedqueue.o $(OBJPATH)/linked_blockingqueue.o $(OBJPATH)/thread_pool.o $(OBJPATH)/Command_main.o

all: $(OBJS) $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -g -o $@ $(OBJS) -lpthread

$(OBJPATH)/linkedlist.o: $(SRCPATH)/linkedlist.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/linkedqueue.o: $(SRCPATH)/linkedqueue.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/linked_blockingqueue.o: $(SRCPATH)/linked_blockingqueue.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/thread_pool.o: $(SRCPATH)/thread_pool.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/Command_main.o: $(SRCPATH)/main.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

clean:
	-rm -rf $(EXEC) $(OBJS)
