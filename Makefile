EXECPATH = bin
OBJPATH = obj
INCLUDEPATH = lib/include
SRCPATH = Observer State Singleton Adapter
CC = gcc

all:
	$(foreach path,$(SRCPATH), make -C $(path);)

clean:
	$(foreach path, $(SRCPATH), make clean -C $(path);)
