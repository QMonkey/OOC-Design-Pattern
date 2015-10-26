EXECPATH = ../bin
OBJPATH = ../obj/Prototype
INCLUDEPATH = include
LIBPATH = ../lib/include
SRCPATH = src
CC = gcc
OPTIONS = -Wall -fms-extensions

EXEC = $(EXECPATH)/Prototype
OBJS = $(OBJPATH)/abstract_number_container.o $(OBJPATH)/multiple_of_2_container.o $(OBJPATH)/multiple_of_3_container.o $(OBJPATH)/main.o

all: dir build

dir:
	mkdir -p $(OBJPATH)
	mkdir -p $(EXECPATH)

build: $(OBJS) $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -g -o $@ $(OBJS)

$(OBJPATH)/abstract_number_container.o: $(SRCPATH)/abstract_number_container.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/multiple_of_2_container.o: $(SRCPATH)/multiple_of_2_container.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/multiple_of_3_container.o: $(SRCPATH)/multiple_of_3_container.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/main.o: $(SRCPATH)/main.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

clean:
	-rm -rf $(EXEC) $(OBJS)
