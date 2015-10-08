#include <stdio.h>

#include "iwidget.h"
#include "linux_widget.h"

static void LinuxWidget_show(IWidget*);

LinuxWidget* constructLinuxWidget(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	LinuxWidget* linuxWidget = addr;
	linuxWidget->show = LinuxWidget_show;

	return linuxWidget;
}

void destructLinuxWidget(LinuxWidget* linuxWidget)
{
}

void LinuxWidget_show(IWidget* iwidget)
{
	printf("Linux widget!\n");
}
