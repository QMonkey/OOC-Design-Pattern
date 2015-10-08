#include <stdio.h>

#include "base.h"
#include "itravel_strategy.h"
#include "airplane_strategy.h"

static void AirplaneStrategy_travel(ITravelStrategy*);

AirplaneStrategy* constructAirplaneStrategy(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	AirplaneStrategy* airplaneStrategy = addr;

	airplaneStrategy->travel = AirplaneStrategy_travel;

	return airplaneStrategy;
}

void destructAirplaneStrategy(AirplaneStrategy* airplaneStrategy)
{
}

void AirplaneStrategy_travel(ITravelStrategy* itravelStrategy)
{
	printf("Travel by airplane.\n");
}
