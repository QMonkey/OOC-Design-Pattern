#ifndef ABSTRACT_CAR_H
#define ABSTRACT_CAR_H

#include "icar.h"

typedef struct _AbstractCar AbstractCar;

struct _AbstractCar
{
	char* body;
	char* engine;
	char* wheel;

	union
	{
		ICar;
		ICar icar;
	};
};

extern void AbstractCar_construct(void*);
extern void AbstractCar_destruct(AbstractCar*);

#endif
