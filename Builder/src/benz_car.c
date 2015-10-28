#include <stdio.h>

#include "icar.h"
#include "abstract_car.h"
#include "benz_car.h"

static void BenzCar_run(ICar*);

BenzCar* BenzCar_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	BenzCar* benzCar = addr;

	AbstractCar_construct(&benzCar->abstractCar);
	benzCar->run = BenzCar_run;

	return benzCar;
}

void BenzCar_destruct(BenzCar* benzCar)
{
	AbstractCar_destruct(&benzCar->abstractCar);
}

void BenzCar_run(ICar* icar)
{
	printf("Benz car run!\n");
}
