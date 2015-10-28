#include <stdio.h>
#include <stdlib.h>

#include "base.h"
#include "icar.h"
#include "ibuilder.h"
#include "benz_car.h"
#include "benz_builder.h"

static void BenzBuilder_buildBody(IBuilder*);
static void BenzBuilder_buildEngine(IBuilder*);
static void BenzBuilder_buildWheel(IBuilder*);
static ICar* BenzBuilder_getCar(IBuilder*);

BenzBuilder* BenzBuilder_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	BenzBuilder* benzBuilder = addr;
	benzBuilder->benzCar = new (BenzCar);
	if (benzBuilder->benzCar == NULL)
	{
		return NULL;
	}

	benzBuilder->buildBody = BenzBuilder_buildBody;
	benzBuilder->buildEngine = BenzBuilder_buildEngine;
	benzBuilder->buildWheel = BenzBuilder_buildWheel;
	benzBuilder->getCar = BenzBuilder_getCar;

	return benzBuilder;
}

void BenzBuilder_destruct(BenzBuilder* benzBuilder)
{
	delete (BenzCar, benzBuilder->benzCar);
}

void BenzBuilder_buildBody(IBuilder* ibuilder)
{
	BenzBuilder* benzBuilder = container_of(ibuilder, BenzBuilder, ibuilder);
	benzBuilder->benzCar->body = "Benz body";
}

void BenzBuilder_buildEngine(IBuilder* ibuilder)
{
	BenzBuilder* benzBuilder = container_of(ibuilder, BenzBuilder, ibuilder);
	benzBuilder->benzCar->engine = "Benz engine";
}

void BenzBuilder_buildWheel(IBuilder* ibuilder)
{
	BenzBuilder* benzBuilder = container_of(ibuilder, BenzBuilder, ibuilder);
	benzBuilder->benzCar->wheel = "Benz wheel";
}

ICar* BenzBuilder_getCar(IBuilder* ibuilder)
{
	BenzBuilder* benzBuilder = container_of(ibuilder, BenzBuilder, ibuilder);
	return &benzBuilder->benzCar->icar;
}
