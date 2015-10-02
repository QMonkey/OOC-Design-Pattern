#include <stdio.h>

#include "iobserver.h"
#include "observed.h"
#include "observer.h"

const int OBSERVER_SIZE = 10;

int main()
{
	Observed *observed = newObserved();
	IObserved *iobserved = &observed->iobserved;

	Observer *observers[OBSERVER_SIZE];
	int i;
	for(i = 0; i < OBSERVER_SIZE; ++i)
	{
		observers[i] = newObserver();
		observed->iobserved.registerObserver(iobserved, &observers[i]->iobserver);
		printf("%p\n", &observers[i]->iobserver);
	}
	printf("\n");

	iobserved->notifyObservers(iobserved);

	for(i = 0; i < OBSERVER_SIZE; ++i)
	{
		deleteObserver(observers[i]);
	}
	deleteObserved(observed);

	return 0;
}
