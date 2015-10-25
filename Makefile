EXECPATH = bin
OBJPATH = obj
INCLUDEPATH = lib/include
SRCPATH = Observer State Singleton Adapter Decorator Strategy Iterator Command Composite FactoryMethod  AbstractFactory TemplateMethod Proxy Facade
CC = gcc

all:
	mkdir -p $(OBJPATH) $(EXECPATH)
	$(foreach path,$(SRCPATH), make -C $(path);)

clean:
	$(foreach path, $(SRCPATH), make clean -C $(path);)
