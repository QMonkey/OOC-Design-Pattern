#include <stdio.h>

#include "ibutton.h"
#include "mac_button.h"

static void MacButton_click(IButton*);

MacButton* constructMacButton(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	MacButton* macButton = addr;
	macButton->click = MacButton_click;

	return macButton;
}

void destructMacButton(MacButton* macButton)
{
}

void MacButton_click(IButton* ibutton)
{
	printf("Mac button!\n");
}
