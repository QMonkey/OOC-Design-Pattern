#include <stdio.h>
#include <stdlib.h>

#include "base.h"
#include "icar.h"
#include "ibuilder.h"
#include "audi_car.h"
#include "audi_builder.h"

static void AudiBuilder_buildBody(IBuilder*);
static void AudiBuilder_buildEngine(IBuilder*);
static void AudiBuilder_buildWheel(IBuilder*);
static ICar* AudiBuilder_getCar(IBuilder*);

AudiBuilder* AudiBuilder_construct(void* addr)
{
	if (addr == NULL)
	{
		return addr;
	}

	AudiBuilder* audiBuilder = addr;
	audiBuilder->audiCar = new (AudiCar);
	if (audiBuilder->audiCar == NULL)
	{
		return NULL;
	}

	audiBuilder->buildBody = AudiBuilder_buildBody;
	audiBuilder->buildEngine = AudiBuilder_buildEngine;
	audiBuilder->buildWheel = AudiBuilder_buildWheel;
	audiBuilder->getCar = AudiBuilder_getCar;

	return audiBuilder;
}

void AudiBuilder_destruct(AudiBuilder* audiBuilder)
{
	delete (AudiCar, audiBuilder->audiCar);
}

void AudiBuilder_buildBody(IBuilder* ibuilder)
{
	AudiBuilder* audiBuilder = container_of(ibuilder, AudiBuilder, ibuilder);
	audiBuilder->audiCar->body = "Audi body";
}

void AudiBuilder_buildEngine(IBuilder* ibuilder)
{
	AudiBuilder* audiBuilder = container_of(ibuilder, AudiBuilder, ibuilder);
	audiBuilder->audiCar->engine = "Audi engine";
}

void AudiBuilder_buildWheel(IBuilder* ibuilder)
{
	AudiBuilder* audiBuilder = container_of(ibuilder, AudiBuilder, ibuilder);
	audiBuilder->audiCar->wheel = "Audi wheel";
}

ICar* AudiBuilder_getCar(IBuilder* ibuilder)
{
	AudiBuilder* audiBuilder = container_of(ibuilder, AudiBuilder, ibuilder);
	return &audiBuilder->audiCar->icar;
}
