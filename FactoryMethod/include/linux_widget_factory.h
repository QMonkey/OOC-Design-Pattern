#ifndef LINUX_WIDGET_FACTORY_H
#define LINUX_WIDGET_FACTORY_H

#include "ifactory.h"

typedef struct _LinuxWidgetFactory LinuxWidgetFactory;

struct _LinuxWidgetFactory
{
	union
	{
		IFactory;
		IFactory ifactory;
	};
};

extern LinuxWidgetFactory* LinuxWidgetFactory_construct(void*);
extern void LinuxWidgetFactory_destruct(LinuxWidgetFactory*);

#endif
