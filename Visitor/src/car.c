#include <stdio.h>

#include "base.h"
#include "icar_element.h"
#include "icar_element_visitor.h"
#include "wheel.h"
#include "engine.h"
#include "body.h"
#include "car.h"

static void Car_accept(Car*, ICarElementVisitor*);

Car* Car_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	Car* car = addr;
	car->elements = malloc(sizeof(ICarElement*) * 3);
	car->elements[0] = &new (Wheel)->icarElement;
	car->elements[1] = &new (Engine)->icarElement;
	car->elements[2] = &new (Body)->icarElement;

	car->accept = Car_accept;

	return car;
}

void Car_destruct(Car* car)
{
	int i;
	for (i = 0; i < 3; ++i)
	{
		// TODO delete
	}

	free(car->elements);
}

void Car_accept(Car* car, ICarElementVisitor* carElementVisitor)
{
	int i;
	for (i = 0; i < 3; ++i)
	{
		ICarElement* icarElement = car->elements[i];
		icarElement->accept(icarElement, carElementVisitor);
	}
}
