#include <stdio.h>

#include "ibutton.h"
#include "windows_button.h"

static void WindowsButton_click(IButton*);

extern WindowsButton* constructWindowsButton(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	WindowsButton* windowsButton = addr;
	windowsButton->click = WindowsButton_click;

	return windowsButton;
}

extern void destructWindowsButton(WindowsButton* windowsButon)
{
}

static void WindowsButton_click(IButton* ibutton)
{
	printf("Windows button!\n");
}
