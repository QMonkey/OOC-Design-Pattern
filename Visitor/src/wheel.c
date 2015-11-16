#include <stdio.h>

#include "base.h"
#include "icar_element.h"
#include "icar_element_visitor.h"
#include "wheel.h"

static char* Wheel_getName(ICarElement*);
static void Wheel_accept(ICarElement*, ICarElementVisitor*);

Wheel* Wheel_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	Wheel* wheel = addr;

	wheel->getName = Wheel_getName;
	wheel->accept = Wheel_accept;

	return wheel;
}

void Wheel_destruct(Wheel* wheel)
{
}

char* Wheel_getName(ICarElement* icarElement)
{
	return "Wheel";
}

void Wheel_accept(ICarElement* icarElement, ICarElementVisitor* carElementVisitor)
{
	Wheel* wheel = container_of(icarElement, Wheel, icarElement);
	carElementVisitor->visitWheel(carElementVisitor, wheel);
}
