#include <stdio.h>

#include "iwidget.h"
#include "windows_widget.h"

static void WindowsWidget_show(IWidget*);

WindowsWidget* WindowsWidget_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	WindowsWidget* windowsWidget = addr;
	windowsWidget->show = WindowsWidget_show;

	return windowsWidget;
}

void WindowsWidget_destruct(WindowsWidget* windowsWidget)
{
}

void WindowsWidget_show(IWidget* iwidget)
{
	printf("Windows Widget!\n");
}
