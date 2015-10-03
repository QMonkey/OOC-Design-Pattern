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

extern Window* constructWindow(void*, int, int);
extern void destructWindow(Window*);

#endif
