#include <stdio.h>
#include <stdlib.h>

#include "base.h"
#include "observer.h"

static void Observer_handle(IObserver*);

Observer* newObserver()
{
	return constructObserver(malloc(sizeof(Observer)));
}

Observer* constructObserver(void *addr)
{
	if(addr == NULL)
	{
		return NULL;
	}

	Observer *observer = addr;
	observer->iobserver.handle = Observer_handle;

	return observer;
}

void destructObserver(Observer *observer)
{
}

void deleteObserver(Observer *observer)
{
	destructObserver(observer);
	free(observer);
}

void Observer_handle(IObserver *iobserver)
{
	Observer *observer = container_of(iobserver, Observer, iobserver);
	printf("%p\n", observer);
}
