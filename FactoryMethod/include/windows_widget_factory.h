#ifndef WINDOWS_WIDGET_FACTORY_H
#define WINDOWS_WIDGET_FACTORY_H

#include "ifactory.h"

typedef struct _WindowsWidgetFactory WindowsWidgetFactory;

struct _WindowsWidgetFactory
{
	union
	{
		IFactory;
		IFactory ifactory;
	};
};

extern WindowsWidgetFactory* constructWindowsWidgetFactory(void*);
extern void destructWindowsWidgetFactory(WindowsWidgetFactory*);

#endif
