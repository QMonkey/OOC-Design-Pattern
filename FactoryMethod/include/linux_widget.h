#ifndef LINUX_WIDGET_H
#define LINUX_WIDGET_H

#include "iwidget.h"

typedef struct _LinuxWidget LinuxWidget;

struct _LinuxWidget
{
	union
	{
		IWidget;
		IWidget iwidget;
	};
};

extern LinuxWidget* LinuxWidget_construct(void*);
extern void LinuxWidget_destruct(LinuxWidget*);

#endif
