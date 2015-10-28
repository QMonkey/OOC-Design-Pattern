#include <stdio.h>

#include "icar.h"
#include "abstract_car.h"
#include "audi_car.h"

static void AudiCar_run(ICar*);

AudiCar* AudiCar_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	AudiCar* audiCar = addr;

	AbstractCar_construct(&audiCar->abstractCar);
	audiCar->run = AudiCar_run;

	return audiCar;
}

void AudiCar_destruct(AudiCar* audiCar)
{
	AbstractCar_destruct(&audiCar->abstractCar);
}

void AudiCar_run(ICar* icar)
{
	printf("Audi car run!\n");
}
