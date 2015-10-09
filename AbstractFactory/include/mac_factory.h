#ifndef MAC_FACTORY_H
#define MAC_FACTORY_H

#include "ifactory.h"

typedef struct _MacFactory MacFactory;

struct _MacFactory
{
	union
	{
		IFactory;
		IFactory ifactory;
	};
};

extern MacFactory* constructMacFactory(void*);
extern void destructMacFactory(MacFactory*);

#endif
