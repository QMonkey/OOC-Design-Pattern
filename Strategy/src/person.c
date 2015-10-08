#include <stdio.h>

#include "base.h"
#include "itravel_strategy.h"
#include "person.h"

static void Person_setTravelStrategy(Person*, ITravelStrategy*);
static void Person_travel(Person*);

Person* constructPerson(void* addr, ITravelStrategy* travelStrategy)
{
	if (addr == NULL)
	{
		return NULL;
	}

	Person* person = addr;
	person->travelStrategy = travelStrategy;

	person->setTravelStrategy = Person_setTravelStrategy;
	person->travel = Person_travel;

	return person;
}

void destructPerson(Person* person)
{
}

void Person_setTravelStrategy(Person* person, ITravelStrategy* travelStrategy)
{
	person->travelStrategy = travelStrategy;
}

void Person_travel(Person* person)
{
	person->travelStrategy->travel(person->travelStrategy);
}
