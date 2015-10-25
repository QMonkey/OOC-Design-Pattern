#ifndef WINDOWS_FACTORY_H
#define WINDOWS_FACTORY_H

#include "ifactory.h"

typedef struct _WindowsFactory WindowsFactory;

struct _WindowsFactory
{
	union
	{
		IFactory;
		IFactory ifactory;
	};
};

extern WindowsFactory* WindowsFactory_construct(void*);
extern void WindowsFactory_destruct(WindowsFactory*);

#endif
