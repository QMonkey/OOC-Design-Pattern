#include <stdio.h>

#include "base.h"
#include "iwidget.h"
#include "ifactory.h"
#include "windows_widget.h"
#include "windows_widget_factory.h"

static IWidget* WindowsWidgetFactory_createWidget(IFactory*);

WindowsWidgetFactory* WindowsWidgetFactory_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	WindowsWidgetFactory* windowsWidgetFactory = addr;
	windowsWidgetFactory->createWidget = WindowsWidgetFactory_createWidget;

	return windowsWidgetFactory;
}

void WindowsWidgetFactory_destruct(WindowsWidgetFactory* windowsWidgetFactory)
{
}

IWidget* WindowsWidgetFactory_createWidget(IFactory* ifactory)
{
	return &new (WindowsWidget)->iwidget;
}
