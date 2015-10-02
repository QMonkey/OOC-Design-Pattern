EXECPATH = bin
OBJPATH = obj
INCLUDEPATH = lib/include
SRCPATH = Observer
CC = gcc

EXEC = $(EXECPATH)/Observer
OBJS = $(OBJPATH)/observed.o $(OBJPATH)/observer.o $(OBJPATH)/main.o

all: $(OBJS) $(EXEC)

$(EXECPATH)/Observer: $(OBJS)
	$(CC) -g -o $@ $(OBJS)

$(OBJPATH)/observed.o: $(SRCPATH)/observed.c
	$(CC) -g -c $< -I $(INCLUDEPATH) -o $@

$(OBJPATH)/observer.o: $(SRCPATH)/observer.c
	$(CC) -g -c $< -I $(INCLUDEPATH) -o $@

$(OBJPATH)/main.o: $(SRCPATH)/main.c
	$(CC) -g -c $< -I $(INCLUDEPATH) -o $@

clean:
	-rm -rf $(EXEC) $(OBJS)
