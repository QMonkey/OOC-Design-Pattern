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

extern Observer* constructObserver(void*);
extern void destructObserver(Observer*);

#endif
