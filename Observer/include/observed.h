#ifndef OBSERVED_H
#define OBSERVED_H

#include <stddef.h>

#include "iobserver.h"

typedef struct _Observed Observed;

struct _Observed
{
	IObserver** observers;
	size_t count;
	size_t size;

	union
	{
		IObserved;
		IObserved iobserved;
	};
};

extern Observed* Observed_construct(void*);
extern void Observed_destruct(Observed*);

#endif
