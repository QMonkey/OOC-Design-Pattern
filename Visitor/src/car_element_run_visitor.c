#include <stdio.h>

#include "icar_element_visitor.h"
#include "wheel.h"
#include "engine.h"
#include "body.h"
#include "car_element_run_visitor.h"

static void CarElementRunVisitor_visitWheel(ICarElementVisitor*, Wheel*);
static void CarElementRunVisitor_visitEngine(ICarElementVisitor*, Engine*);
static void CarElementRunVisitor_visitBody(ICarElementVisitor*, Body*);

CarElementRunVisitor* CarElementRunVisitor_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	CarElementRunVisitor* carElementRunVisitor = addr;

	carElementRunVisitor->visitWheel = CarElementRunVisitor_visitWheel;
	carElementRunVisitor->visitEngine = CarElementRunVisitor_visitEngine;
	carElementRunVisitor->visitBody = CarElementRunVisitor_visitBody;

	return carElementRunVisitor;
}

void CarElementRunVisitor_destruct(CarElementRunVisitor* carElementRunVisitor)
{
}

void CarElementRunVisitor_visitWheel(ICarElementVisitor* icarElementVisitor, Wheel* wheel)
{
	printf("Visit %s!\n", wheel->getName(&wheel->icarElement));
}

void CarElementRunVisitor_visitEngine(ICarElementVisitor* icarElementVisitor, Engine* engine)
{
	printf("Visit %s!\n", engine->getName(&engine->icarElement));
}

void CarElementRunVisitor_visitBody(ICarElementVisitor* icarElementVisitor, Body* body)
{
	printf("Visit %s!\n", body->getName(&body->icarElement));
}
