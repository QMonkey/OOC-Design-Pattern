#ifndef BENZ_BUILDER_H
#define BENZ_BUILDER_H

#include "ibuilder.h"
#include "benz_car.h"

typedef struct _BenzBuilder BenzBuilder;

struct _BenzBuilder
{
	BenzCar* benzCar;

	union
	{
		IBuilder;
		IBuilder ibuilder;
	};
};

extern BenzBuilder* BenzBuilder_construct(void*);
extern void BenzBuilder_destruct(BenzBuilder*);

#endif
