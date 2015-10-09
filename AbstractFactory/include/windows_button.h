#ifndef WINDOWS_BUTTON_H
#define WINDOWS_BUTTON_H

#include "ibutton.h"

typedef struct _WindowsButton WindowsButton;

struct _WindowsButton
{
	union
	{
		IButton;
		IButton ibutton;
	};
};

extern WindowsButton* constructWindowsButton(void*);
extern void destructWindowsButton(WindowsButton*);

#endif
