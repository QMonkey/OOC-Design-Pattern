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

extern WindowsWidget* constructWindowsWidget(void*);
extern void destructWindowsWidget(WindowsWidget*);

#endif
