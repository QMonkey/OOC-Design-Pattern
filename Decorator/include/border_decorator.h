#ifndef BORDER_DECORATOR_H
#define BORDER_DECORATOR_H

#include "iwindow.h"

typedef struct _BorderDecorator BorderDecorator;

struct _BorderDecorator
{
	IWindow* window;

	void (*setWindow)(BorderDecorator*, IWindow*);
	union
	{
		IWindow;
		IWindow iwindow;
	};
};

extern BorderDecorator* BorderDecorator_construct(void*, IWindow*);
extern void BorderDecorator_destruct(BorderDecorator*);

#endif
