#ifndef MAC_WIDGET_FACTORY_H
#define MAC_WIDGET_FACTORY_H

#include "ifactory.h"

typedef struct _MacWidgetFactory MacWidgetFactory;

struct _MacWidgetFactory
{
	union
	{
		IFactory;
		IFactory ifactory;
	};
};

extern MacWidgetFactory* constructMacWidgetFactory(void*);
extern void destructMacWidgetFactory(MacWidgetFactory*);

#endif
