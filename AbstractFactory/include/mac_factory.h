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

extern MacFactory* MacFactory_construct(void*);
extern void MacFactory_destruct(MacFactory*);

#endif
