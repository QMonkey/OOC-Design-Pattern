#ifndef BENZ_CAR_H
#define BENZ_CAR_H

#include "abstract_car.h"

typedef struct _BenzCar BenzCar;

struct _BenzCar
{
	union
	{
		AbstractCar;
		AbstractCar abstractCar;
	};
};

extern BenzCar* BenzCar_construct(void*);
extern void BenzCar_destruct(BenzCar*);

#endif
