#include <stdio.h>

#include "base.h"
#include "iwidget.h"
#include "ifactory.h"
#include "mac_widget.h"
#include "mac_widget_factory.h"

static IWidget* MacWidgetFactory_createWidget(IFactory*);

MacWidgetFactory* MacWidgetFactory_construct(void* addr)
{
	if (addr == NULL)
	{
		return addr;
	}

	MacWidgetFactory* macWidgetFactory = addr;
	macWidgetFactory->createWidget = MacWidgetFactory_createWidget;

	return macWidgetFactory;
}

void MacWidgetFactory_destruct(MacWidgetFactory* macWidgetFactory)
{
}

IWidget* MacWidgetFactory_createWidget(IFactory* ifactory)
{
	return &new (MacWidget)->iwidget;
}
