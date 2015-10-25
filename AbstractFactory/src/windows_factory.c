#include <stdio.h>

#include "base.h"
#include "iwidget.h"
#include "ibutton.h"
#include "ifactory.h"
#include "windows_widget.h"
#include "windows_button.h"
#include "windows_factory.h"

static IWidget* WindowsFactory_createWidget(IFactory*);
static IButton* WindowsFactory_createButton(IFactory*);

WindowsFactory* WindowsFactory_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	WindowsFactory* windowsFactory = addr;
	windowsFactory->createWidget = WindowsFactory_createWidget;
	windowsFactory->createButton = WindowsFactory_createButton;

	return windowsFactory;
}

void WindowsFactory_destruct(WindowsFactory* windowsFactory)
{
}

IWidget* WindowsFactory_createWidget(IFactory* ifactory)
{
	return &new (WindowsWidget)->iwidget;
}

IButton* WindowsFactory_createButton(IFactory* ifactory)
{
	return &new (WindowsButton)->ibutton;
}
