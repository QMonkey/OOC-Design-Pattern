EXECPATH = ../bin
OBJPATH = ../obj/Iterator
INCLUDEPATH = include
LIBPATH = ../lib/include
SRCPATH = src
CC = gcc
OPTIONS = -fms-extensions

EXEC = $(EXECPATH)/Iterator
OBJS = $(OBJPATH)/arraylist.o $(OBJPATH)/linkedlist.o $(OBJPATH)/arraylist_iterator.o $(OBJPATH)/linkedlist_iterator.o $(OBJPATH)/Iterator_main.o

all: $(OBJS) $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -g -o $@ $(OBJS)

$(OBJPATH)/arraylist.o: $(SRCPATH)/arraylist.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/linkedlist.o: $(SRCPATH)/linkedlist.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/arraylist_iterator.o: $(SRCPATH)/arraylist_iterator.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/linkedlist_iterator.o: $(SRCPATH)/linkedlist_iterator.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/Iterator_main.o: $(SRCPATH)/main.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

clean:
	-rm -rf $(EXEC) $(OBJS)
