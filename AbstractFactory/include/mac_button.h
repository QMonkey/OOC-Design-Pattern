#ifndef MAC_BUTTON_H
#define MAC_BUTTON_H

#include "ibutton.h"

typedef struct _MacButton MacButton;

struct _MacButton
{
	union
	{
		IButton;
		IButton ibutton;
	};
};

extern MacButton* constructMacButton(void*);
extern void destructMacButton(MacButton*);

#endif
