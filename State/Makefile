EXECPATH = ../bin
OBJPATH = ../obj
INCLUDEPATH = ../lib/include
CC = gcc

EXEC = $(EXECPATH)/State
OBJS = $(OBJPATH)/observed.o $(OBJPATH)/observer.o $(OBJPATH)/main.o

all: $(OBJS) $(EXEC)

$(EXECPATH)/Observer: $(OBJS)
	$(CC) -g -o $@ $(OBJS)

$(OBJPATH)/observed.o: observed.c
	$(CC) -g -c $< -I $(INCLUDEPATH) -o $@

$(OBJPATH)/observer.o: observer.c
	$(CC) -g -c $< -I $(INCLUDEPATH) -o $@

$(OBJPATH)/main.o: main.c
	$(CC) -g -c $< -I $(INCLUDEPATH) -o $@

clean:
	-rm -rf $(EXEC) $(OBJS)
