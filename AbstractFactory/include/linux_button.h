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

extern LinuxButton* LinuxButton_construct(void*);
extern void LinuxButton_destruct(LinuxButton*);

#endif
