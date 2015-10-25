EXECPATH = ../bin
OBJPATH = ../obj/State
LIBPATH = ../lib/include
INCLUDEPATH = include
SRCPATH=src
CC = gcc
OPTIONS = -Wall -fms-extensions

EXEC = $(EXECPATH)/State
OBJS = $(OBJPATH)/qrcode_state_machine.o $(OBJPATH)/abstract_qrcode_state.o $(OBJPATH)/noqrcode_state.o $(OBJPATH)/qrcode_valid_state.o $(OBJPATH)/qrcode_authorizing_state.o $(OBJPATH)/qrcode_authorized_state.o $(OBJPATH)/main.o

all: dir build

dir:
	mkdir -p $(OBJPATH)
	mkdir -p $(EXECPATH)

build: $(OBJS) $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -g -o $@ $(OBJS)

$(OBJPATH)/qrcode_state_machine.o: $(SRCPATH)/qrcode_state_machine.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/abstract_qrcode_state.o: $(SRCPATH)/abstract_qrcode_state.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/noqrcode_state.o: $(SRCPATH)/noqrcode_state.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/qrcode_valid_state.o: $(SRCPATH)/qrcode_valid_state.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/qrcode_authorizing_state.o: $(SRCPATH)/qrcode_authorizing_state.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/qrcode_authorized_state.o: $(SRCPATH)/qrcode_authorized_state.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/main.o: $(SRCPATH)/main.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

clean:
	-rm -rf $(EXEC) $(OBJS)
