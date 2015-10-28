#ifndef AUDI_BUILDER_H
#define AUDI_BUILDER_H

#include "ibuilder.h"
#include "audi_car.h"

typedef struct _AudiBuilder AudiBuilder;

struct _AudiBuilder
{
	AudiCar* audiCar;

	union
	{
		IBuilder;
		IBuilder ibuilder;
	};
};

extern AudiBuilder* AudiBuilder_construct(void*);
extern void AudiBuilder_destruct(AudiBuilder*);

#endif
