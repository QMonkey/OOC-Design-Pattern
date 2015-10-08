#include <stdio.h>

#include "base.h"
#include "itravel_strategy.h"
#include "train_strategy.h"

static void TrainStrategy_travel(ITravelStrategy*);

TrainStrategy* constructTrainStrategy(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	TrainStrategy* trainStrategy = addr;

	trainStrategy->travel = TrainStrategy_travel;

	return trainStrategy;
}

void destructTrainStrategy(TrainStrategy* trainStrategy)
{
}

void TrainStrategy_travel(ITravelStrategy* itravelStrategy)
{
	printf("Travel by train.\n");
}
