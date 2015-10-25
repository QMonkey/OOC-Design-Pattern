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

extern MacButton* MacButton_construct(void*);
extern void MacButton_destruct(MacButton*);

#endif
