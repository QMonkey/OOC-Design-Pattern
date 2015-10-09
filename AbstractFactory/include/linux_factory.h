#ifndef LINUX_FACTORY_H
#define LINUX_FACTORY_H

#include "ifactory.h"

typedef struct _LinuxFactory LinuxFactory;

struct _LinuxFactory
{
	union
	{
		IFactory;
		IFactory ifactory;
	};
};

extern LinuxFactory* constructLinuxFactory(void*);
extern void destructLinuxFactory(LinuxFactory*);

#endif
