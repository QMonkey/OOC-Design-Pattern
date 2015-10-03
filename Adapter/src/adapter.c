#include <stdio.h>
#include <stdlib.h>

#include "base.h"
#include "adaptee.h"
#include "adapter.h"

static long Adapter_powerOf2(ITarget*, int);
static void Adapter_setAdaptee(Adapter*, IAdaptee*);

Adapter* constructAdapter(void *addr, IAdaptee *idaptee)
{
	if(addr == NULL)
	{
		return NULL;
	}

	Adapter *adapter = addr;
	adapter->iadaptee = idaptee;

	adapter->powerOf2 = Adapter_powerOf2;
	adapter->setAdaptee = Adapter_setAdaptee;

	return adapter;
}

void destructAdapter(Adapter *adapter)
{
}

long Adapter_powerOf2(ITarget *itarget, int exp)
{
	Adapter *adapter = container_of(itarget, Adapter, itarget);
	return adapter->iadaptee->power(adapter->iadaptee, 2, exp);
}

void Adapter_setAdaptee(Adapter *adapter, IAdaptee *iadaptee)
{
	adapter->iadaptee = iadaptee;
}
