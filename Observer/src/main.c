#include <stdio.h>

#include "base.h"
#include "iobserver.h"
#include "observed.h"
#include "observer.h"

const int OBSERVER_SIZE = 10;

int main()
{
	Observed* observed = new (Observed);
	IObserved* iobserved = &observed->iobserved;

	Observer* observers[OBSERVER_SIZE];
	int i;
	for (i = 0; i < OBSERVER_SIZE; ++i)
	{
		observers[i] = new (Observer);
		observed->registerObserver(iobserved, &observers[i]->iobserver);
		printf("handle: %p\n", &observers[i]->iobserver);
	}
	printf("\n");

	iobserved->notifyObservers(iobserved);

	for (i = 0; i < OBSERVER_SIZE; ++i)
	{
		delete (Observer, observers[i]);
	}
	delete (Observed, observed);

	return 0;
}
