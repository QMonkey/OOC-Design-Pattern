#include <stdio.h>
#include <stdlib.h>

#include "base.h"
#include "icar.h"
#include "abstract_car.h"

static void AbstractCar_run(ICar*);
static void AbstractCar_show(ICar*);

void AbstractCar_construct(void* addr)
{
	if (addr == NULL)
	{
		return;
	}

	AbstractCar* abstractCar = addr;

	abstractCar->run = AbstractCar_run;
	abstractCar->show = AbstractCar_show;
}

void AbstractCar_destruct(AbstractCar* abstractCar)
{
}

void AbstractCar_run(ICar* icar)
{
	fprintf(stderr, "Unsupported operation!\n");
	abort();
}

void AbstractCar_show(ICar* icar)
{
	AbstractCar* abstractCar = container_of(icar, AbstractCar, icar);
	printf("Body: %s,\nEngine: %s,\nWheel: %s\n", abstractCar->body, abstractCar->engine, abstractCar->wheel);
}
