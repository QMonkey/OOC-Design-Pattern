#include <stdio.h>

#include "base.h"
#include "iwidget.h"
#include "ibutton.h"
#include "ifactory.h"
#include "mac_widget.h"
#include "mac_button.h"
#include "mac_factory.h"

static IWidget* MacFactory_createWidget(IFactory*);
static IButton* MacFactory_createButton(IFactory*);

MacFactory* MacFactory_construct(void* addr)
{
	if (addr == NULL)
	{
		return addr;
	}

	MacFactory* macFactory = addr;
	macFactory->createWidget = MacFactory_createWidget;
	macFactory->createButton = MacFactory_createButton;

	return macFactory;
}

void MacFactory_destruct(MacFactory* macFactory)
{
}

IWidget* MacFactory_createWidget(IFactory* ifactory)
{
	return &new (MacWidget)->iwidget;
}

IButton* MacFactory_createButton(IFactory* ifactory)
{
	return &new (MacButton)->ibutton;
}
