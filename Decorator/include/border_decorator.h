#ifndef BORDER_DECORATOR_H
#define BORDER_DECORATOR_H

#include "iwindow.h"

typedef struct _BorderDecorator BorderDecorator;

struct _BorderDecorator
{
	IWindow *window;

	void (*setWindow)(BorderDecorator*, IWindow*);
	union
	{
		IWindow;
		IWindow iwindow;
	};
};

extern BorderDecorator* constructBorderDecorator(void*, IWindow*);
extern void destructBorderDecorator(BorderDecorator*);

#endif
