#include <stdio.h>

#include "icar.h"
#include "ibuilder.h"
#include "producer.h"

static void Producer_setBuilder(Producer*, IBuilder*);
static ICar* Producer_produce(Producer*);

Producer* Producer_construct(void* addr, IBuilder* builder)
{
	if (addr == NULL)
	{
		return NULL;
	}

	Producer* producer = addr;
	producer->builder = builder;

	producer->setBuilder = Producer_setBuilder;
	producer->produce = Producer_produce;

	return producer;
}

void Producer_destruct(Producer* producer)
{
}

void Producer_setBuilder(Producer* producer, IBuilder* builder)
{
	producer->builder = builder;
}

ICar* Producer_produce(Producer* producer)
{
	producer->builder->buildBody(producer->builder);
	producer->builder->buildEngine(producer->builder);
	producer->builder->buildWheel(producer->builder);
	return producer->builder->getCar(producer->builder);
}
