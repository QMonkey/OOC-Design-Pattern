#include <stdio.h>

#include "ibutton.h"
#include "linux_button.h"

static void LinuxButton_click(IButton*);

LinuxButton* constructLinuxButton(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	LinuxButton* linuxButton = addr;
	linuxButton->click = LinuxButton_click;

	return linuxButton;
}

void destructLinuxButton(LinuxButton* linuxButton)
{
}

void LinuxButton_click(IButton* ibutton)
{
	printf("Linux button!\n");
}
