#ifndef OBSERVER_H
#define OBSERVER_H

#include "iobserver.h"

typedef struct _Observer Observer;

struct _Observer
{
	union
	{
		IObserver;
		IObserver iobserver;
	};
};

extern Observer* Observer_construct(void*);
extern void Observer_destruct(Observer*);

#endif
