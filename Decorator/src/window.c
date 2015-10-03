#include <stdio.h>

#include "base.h"
#include "iwindow.h"
#include "window.h"

static void Window_draw(IWindow*);

Window* constructWindow(void *addr, int height, int width)
{
	if(addr == NULL)
	{
		return NULL;
	}

	Window *window = addr;
	window->height = height;
	window->width = width;

	window->draw = Window_draw;

	return window;
}

void destructWindow(Window *window)
{
}

void Window_draw(IWindow *iwindow)
{
	Window *window = container_of(iwindow, Window, iwindow);
	printf("draw window: height=%d, weight=%d\n", window->height, window->width);
}
