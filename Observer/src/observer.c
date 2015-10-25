#include <stdio.h>

#include "base.h"
#include "observer.h"

static void Observer_handle(IObserver*);

Observer* Observer_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	Observer* observer = addr;
	observer->handle = Observer_handle;

	return observer;
}

void Observer_destruct(Observer* observer)
{
}

void Observer_handle(IObserver* iobserver)
{
	Observer* observer = container_of(iobserver, Observer, iobserver);
	printf("handle: %p\n", observer);
}
