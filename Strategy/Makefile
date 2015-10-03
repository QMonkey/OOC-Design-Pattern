EXECPATH = ../bin
OBJPATH = ../obj
INCLUDEPATH = include
LIBPATH = ../lib/include
SRCPATH = src
CC = gcc
OPTIONS = -fms-extensions

EXEC = $(EXECPATH)/Strategy
OBJS = $(OBJPATH)/person.o $(OBJPATH)/airplane_strategy.o $(OBJPATH)/train_strategy.o $(OBJPATH)/Strategy_main.o

all: $(OBJS) $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -g -o $@ $(OBJS)

$(OBJPATH)/person.o: $(SRCPATH)/person.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/airplane_strategy.o: $(SRCPATH)/airplane_strategy.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/train_strategy.o: $(SRCPATH)/train_strategy.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/Strategy_main.o: $(SRCPATH)/main.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

clean:
	-rm -rf $(EXEC) $(OBJS)
