#ifndef PERSON_H
#define PERSON_H

#include "itravel_strategy.h"

typedef struct _Person Person;

struct _Person
{
	ITravelStrategy* travelStrategy;

	void (*setTravelStrategy)(Person*, ITravelStrategy*);
	void (*travel)(Person*);
};

extern Person* constructPerson(void*, ITravelStrategy*);
extern void destructPerson(Person*);

#endif
