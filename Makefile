EXECPATH = bin
OBJPATH = obj
INCLUDEPATH = lib/include
SRCPATH = Observer State Singleton Adapter Decorator Strategy Iterator Command Composite FactoryMethod  AbstractFactory TemplateMethod Proxy Facade Bridge Prototype Builder Memento ChainOfResponsibility Mediator Flyweight Visitor
CC = gcc

all:
	mkdir -p $(OBJPATH) $(EXECPATH)
	$(foreach path,$(SRCPATH), make -C $(path);)

clean:
	$(foreach path, $(SRCPATH), make clean -C $(path);)
