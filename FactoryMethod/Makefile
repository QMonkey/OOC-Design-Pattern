EXECPATH = ../bin
OBJPATH = ../obj/FactoryMethod
INCLUDEPATH = include
LIBPATH = ../lib/include
SRCPATH = src
CC = gcc
OPTIONS = -Wall -fms-extensions

EXEC = $(EXECPATH)/FactoryMethod
OBJS = $(OBJPATH)/linux_widget_factory.o $(OBJPATH)/mac_widget_factory.o $(OBJPATH)/windows_widget_factory.o $(OBJPATH)/linux_widget.o $(OBJPATH)/mac_widget.o $(OBJPATH)/windows_widget.o $(OBJPATH)/main.o

all: dir build

dir:
	mkdir -p $(OBJPATH)
	mkdir -p $(EXECPATH)

build: $(OBJS) $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -g -o $@ $(OBJS)

$(OBJPATH)/linux_widget_factory.o: $(SRCPATH)/linux_widget_factory.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/mac_widget_factory.o: $(SRCPATH)/mac_widget_factory.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/windows_widget_factory.o: $(SRCPATH)/windows_widget_factory.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/linux_widget.o: $(SRCPATH)/linux_widget.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/mac_widget.o: $(SRCPATH)/mac_widget.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/windows_widget.o: $(SRCPATH)/windows_widget.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/main.o: $(SRCPATH)/main.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

clean:
	-rm -rf $(EXEC) $(OBJS)
