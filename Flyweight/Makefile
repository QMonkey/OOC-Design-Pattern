EXECPATH = ../bin
OBJPATH = ../obj/Flyweight
INCLUDEPATH = include
LIBPATH = ../lib/include
SRCPATH = src
CC = gcc
OPTIONS = -Wall -fms-extensions

EXEC = $(EXECPATH)/Flyweight
OBJS = $(OBJPATH)/read_permission.o $(OBJPATH)/write_permission.o $(OBJPATH)/readwrite_permission.o $(OBJPATH)/permission_factory.o $(OBJPATH)/main.o

all: dir build

dir:
	mkdir -p $(OBJPATH)
	mkdir -p $(EXECPATH)

build: $(OBJS) $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -g -o $@ $(OBJS) -lpthread

$(OBJPATH)/read_permission.o: $(SRCPATH)/read_permission.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/write_permission.o: $(SRCPATH)/write_permission.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/readwrite_permission.o: $(SRCPATH)/readwrite_permission.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/permission_factory.o: $(SRCPATH)/permission_factory.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/main.o: $(SRCPATH)/main.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

clean:
	-rm -rf $(EXEC) $(OBJS)
