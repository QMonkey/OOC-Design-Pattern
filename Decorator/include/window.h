#ifndef WINDOW_H
#define WINDOW_H

#include "iwindow.h"

typedef struct _Window Window;

struct _Window
{
	int height;
	int width;

	union
	{
		IWindow;
		IWindow iwindow;
	};
};

extern Window* Window_construct(void*, int, int);
extern void Window_destruct(Window*);

#endif
