EXECPATH = ../bin
OBJPATH = ../obj/Mediator
INCLUDEPATH = include
LIBPATH = ../lib/include
SRCPATH = src
CC = gcc
OPTIONS = -Wall -fms-extensions

EXEC = $(EXECPATH)/Mediator
OBJS = $(OBJPATH)/department.o $(OBJPATH)/user.o $(OBJPATH)/department_user.o $(OBJPATH)/mediator.o $(OBJPATH)/main.o

all: dir build

dir:
	mkdir -p $(OBJPATH)
	mkdir -p $(EXECPATH)

build: $(OBJS) $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -g -o $@ $(OBJS)

$(OBJPATH)/department.o: $(SRCPATH)/department.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/user.o: $(SRCPATH)/user.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/department_user.o: $(SRCPATH)/department_user.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/mediator.o: $(SRCPATH)/mediator.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/main.o: $(SRCPATH)/main.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

clean:
	-rm -rf $(EXEC) $(OBJS)
