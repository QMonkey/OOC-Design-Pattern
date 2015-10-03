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

extern Adaptee* constructAdaptee(void*);
extern void destructAdaptee(Adaptee*);

#endif
