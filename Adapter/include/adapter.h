#ifndef ADAPTER_H
#define ADAPTER_H

#include "target.h"
#include "adaptee.h"

typedef struct _Adapter Adapter;

struct _Adapter
{
	IAdaptee *iadaptee;

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
