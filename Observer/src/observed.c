#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "base.h"
#include "observed.h"

static void Observed_registerObserver(IObserved*, IObserver*);
static void Observed_notifyObservers(IObserved*);
static void Observed_removeObserver(IObserved*, IObserver*);

Observed* Observed_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	Observed* observed = addr;
	observed->observers = malloc(sizeof(IObserver*));
	observed->count = 0;
	observed->size = 1;

	observed->registerObserver = Observed_registerObserver;
	observed->notifyObservers = Observed_notifyObservers;
	observed->removeObserver = Observed_removeObserver;

	return observed;
}

void Observed_destruct(Observed* observed)
{
	free(observed->observers);
}

void Observed_registerObserver(IObserved* iobserved, IObserver* observer)
{
	Observed* observed = container_of(iobserved, Observed, iobserved);

	int i;
	for (i = 0; i < observed->count; ++i)
	{
		if (observed->observers[i] == observer)
		{
			return;
		}
	}

	if (observed->count == observed->size)
	{
		int size = observed->size << 1;
		IObserver** observers = malloc(sizeof(IObserver*) * size);
		if (observers == NULL)
		{
			return;
		}

		memcpy(observers, observed->observers,
		       sizeof(IObserver*) * observed->count);
		free(observed->observers);
		observed->observers = observers;
		observed->size = size;
	}

	observed->observers[observed->count++] = observer;
}

void Observed_notifyObservers(IObserved* iobserved)
{
	Observed* observed = container_of(iobserved, Observed, iobserved);

	int i;
	for (i = 0; i < observed->count; ++i)
	{
		IObserver* observer = observed->observers[i];
		observer->handle(observer);
	}
}

void Observed_removeObserver(IObserved* iobserved, IObserver* observer)
{
	Observed* observed = container_of(iobserved, Observed, iobserved);

	int i;
	for (i = 0; i < observed->count; ++i)
	{
		if (observed->observers[i] == observer)
		{
			break;
		}
	}

	if (i == observed->count)
	{
		return;
	}

	--observed->count;
	for (; i < observed->count; ++i)
	{
		observed->observers[i] = observed->observers[i + 1];
	}
}
