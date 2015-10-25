#include <stdio.h>

#include "base.h"
#include "itarget.h"
#include "iadaptee.h"
#include "adapter.h"

static long Adapter_powerOf2(ITarget*, int);
static void Adapter_setAdaptee(Adapter*, IAdaptee*);

Adapter* Adapter_construct(void* addr, IAdaptee* adaptee)
{
	if (addr == NULL)
	{
		return NULL;
	}

	Adapter* adapter = addr;
	adapter->adaptee = adaptee;

	adapter->powerOf2 = Adapter_powerOf2;
	adapter->setAdaptee = Adapter_setAdaptee;

	return adapter;
}

void Adapter_destruct(Adapter* adapter)
{
}

long Adapter_powerOf2(ITarget* itarget, int exp)
{
	Adapter* adapter = container_of(itarget, Adapter, itarget);
	return adapter->adaptee->power(adapter->adaptee, 2, exp);
}

void Adapter_setAdaptee(Adapter* adapter, IAdaptee* adaptee)
{
	adapter->adaptee = adaptee;
}
