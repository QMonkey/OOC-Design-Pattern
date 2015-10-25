EXECPATH = ../bin
OBJPATH = ../obj/Bridge
INCLUDEPATH = include
LIBPATH = ../lib/include
SRCPATH = src
CC = gcc
OPTIONS = -Wall -fms-extensions

EXEC = $(EXECPATH)/Bridge
OBJS = $(OBJPATH)/abstract_message.o $(OBJPATH)/findpwd_message.o $(OBJPATH)/signup_message.o $(OBJPATH)/sms_sender.o $(OBJPATH)/email_sender.o $(OBJPATH)/main.o

all: dir build

dir:
	mkdir -p $(OBJPATH)
	mkdir -p $(EXECPATH)

build: $(OBJS) $(EXEC)

$(EXEC): $(OBJS)
	$(CC) -g -o $@ $(OBJS)

$(OBJPATH)/abstract_message.o: $(SRCPATH)/abstract_message.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/findpwd_message.o: $(SRCPATH)/findpwd_message.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/signup_message.o: $(SRCPATH)/signup_message.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/sms_sender.o: $(SRCPATH)/sms_sender.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/email_sender.o: $(SRCPATH)/email_sender.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

$(OBJPATH)/main.o: $(SRCPATH)/main.c
	$(CC) -g -c $< -I $(LIBPATH) -I $(INCLUDEPATH) -o $@ $(OPTIONS)

clean:
	-rm -rf $(EXEC) $(OBJS)
