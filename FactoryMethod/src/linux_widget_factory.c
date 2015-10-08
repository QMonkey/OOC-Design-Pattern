#include <stdio.h>

#include "base.h"
#include "iwidget.h"
#include "ifactory.h"
#include "linux_widget.h"
#include "linux_widget_factory.h"

static IWidget* LinuxWidgetFactory_createWidget(IFactory*);

LinuxWidgetFactory* constructLinuxWidgetFactory(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	LinuxWidgetFactory* linuxWidgetFactory = addr;
	linuxWidgetFactory->createWidget = LinuxWidgetFactory_createWidget;

	return linuxWidgetFactory;
}

void destructLinuxWidgetFactory(LinuxWidgetFactory* linuxWidgetFactory)
{
}

IWidget* LinuxWidgetFactory_createWidget(IFactory* ifactory)
{
	return &new (LinuxWidget)->iwidget;
}
