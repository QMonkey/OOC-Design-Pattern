#ifndef ADAPTEE_H
#define ADAPTEE_H

#include "iadaptee.h"

typedef struct _Adaptee Adaptee;

struct _Adaptee
{
	union
	{
		IAdaptee;
		IAdaptee iadaptee;
	};
};

extern Adaptee* Adaptee_construct(void*);
extern void Adaptee_destruct(Adaptee*);

#endif
