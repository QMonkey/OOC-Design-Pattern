EXECPATH = ../bin
OBJPATH = ../obj/Interpreter
INCLUDEPATH = include
LIBPATH = ../lib/include
SRCPATH = src
CC = gcc
OPTIONS = -Wall -fms-extensions

EXEC = $(EXECPATH)/Interpreter
OBJS = $(OBJPATH)/plus.o $(OBJPATH)/minus.o $(OBJPATH)/multiply.o $(OBJPATH)/divide.o $(OBJPATH)/number.o $(OBJPATH)/context.o $(OBJPATH)/main.o

all: dir build

dir:
	mkdir -p $(OBJPATH)
	mkdir -p $(EXECPATH)

build: $(OBJS) $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -g -o $@ $(OBJS)

$(OBJPATH)/plus.o: $(SRCPATH)/plus.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/minus.o: $(SRCPATH)/minus.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/multiply.o: $(SRCPATH)/multiply.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/divide.o: $(SRCPATH)/divide.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/number.o: $(SRCPATH)/number.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/context.o: $(SRCPATH)/context.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/main.o: $(SRCPATH)/main.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

clean:
	-rm -rf $(EXEC) $(OBJS)
