#ifndef ADAPTER_H
#define ADAPTER_H

#include "itarget.h"
#include "iadaptee.h"

typedef struct _Adapter Adapter;

struct _Adapter
{
	IAdaptee *adaptee;

	void (*setAdaptee)(Adapter*, IAdaptee*);
	union
	{
		ITarget;
		ITarget itarget;
	};
};

extern Adapter* constructAdapter(void*, IAdaptee*);
extern void destructAdapter(Adapter*);

#endif
