#include <stdio.h>

#include "base.h"
#include "iwindow.h"
#include "border_decorator.h"

static void BorderDecorator_draw(IWindow*);
static void BorderDecorator_setWindow(BorderDecorator*, IWindow*);

BorderDecorator* constructBorderDecorator(void *addr, IWindow *window)
{
	if(addr == NULL)
	{
		return NULL;
	}

	BorderDecorator *borderDecorator = addr;
	borderDecorator->window = window;

	borderDecorator->draw = BorderDecorator_draw;

	return borderDecorator;
}

void destructBorderDecorator(BorderDecorator *borderDecorator)
{
}

void BorderDecorator_draw(IWindow *iwindow)
{
	BorderDecorator *borderDecorator = container_of(iwindow, BorderDecorator, iwindow);
	borderDecorator->window->draw(borderDecorator->window);
	printf("draw border\n");
}

void BorderDecorator_setWindow(BorderDecorator *borderDecorator, IWindow *window)
{
	borderDecorator->window = window;
}
