#ifndef OBSERVED_H
#define OBSERVED_H

#include "iobserver.h"

typedef struct _Observed Observed;

struct _Observed
{
        IObserver **observers;
	size_t count;
	size_t size;

	union
	{
		IObserved;
		IObserved iobserved;
	};
};

extern Observed* constructObserved(void*);
extern void destructObserved(Observed*);

#endif
