#include <stdio.h>

#include "iwidget.h"
#include "mac_widget.h"

static void MacWidget_show(IWidget*);

MacWidget* constructMacWidget(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	MacWidget* macWidget = addr;
	macWidget->show = MacWidget_show;

	return macWidget;
}

void destructMacWidget(MacWidget* macWidget)
{
}

void MacWidget_show(IWidget* iwidget)
{
	printf("Mac widget!\n");
}
