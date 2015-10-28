#ifndef AUDI_CAR_H
#define AUDI_CAR_H

#include "abstract_car.h"

typedef struct _AudiCar AudiCar;

struct _AudiCar
{
	union
	{
		AbstractCar;
		AbstractCar abstractCar;
	};
};

extern AudiCar* AudiCar_construct(void*);
extern void AudiCar_destruct(AudiCar*);

#endif
