#ifndef MAC_WIDGET_H
#define MAC_WIDGET_H

#include "iwidget.h"

typedef struct _MacWidget MacWidget;

struct _MacWidget
{
	union
	{
		IWidget;
		IWidget iwidget;
	};
};

extern MacWidget* constructMacWidget(void*);
extern void destructMacWidget(MacWidget*);

#endif
