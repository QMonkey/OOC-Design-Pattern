#ifndef ADAPTER_H
#define ADAPTER_H

#include "itarget.h"
#include "iadaptee.h"

typedef struct _Adapter Adapter;

struct _Adapter
{
	IAdaptee* adaptee;

	void (*setAdaptee)(Adapter*, IAdaptee*);
	union
	{
		ITarget;
		ITarget itarget;
	};
};

extern Adapter* Adapter_construct(void*, IAdaptee*);
extern void Adapter_destruct(Adapter*);

#endif
