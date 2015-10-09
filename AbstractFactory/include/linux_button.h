#ifndef LINUX_BUTTON_H
#define LINUX_BUTTON_H

#include "ibutton.h"

typedef struct _LinuxButton LinuxButton;

struct _LinuxButton
{
	union
	{
		IButton;
		IButton ibutton;
	};
};

extern LinuxButton* constructLinuxButton(void*);
extern void destructLinuxButton(LinuxButton*);

#endif
