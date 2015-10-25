#ifndef WINDOWS_WIDGET_H
#define WINDOWS_WIDGET_H

#include "iwidget.h"

typedef struct _WindowsWidget WindowsWidget;

struct _WindowsWidget
{
	union
	{
		IWidget;
		IWidget iwidget;
	};
};

extern WindowsWidget* WindowsWidget_construct(void*);
extern void WindowsWidget_destruct(WindowsWidget*);

#endif
