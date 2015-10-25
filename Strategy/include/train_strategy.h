#ifndef TRAIN_STRATEGY_H
#define TRAIN_STRATEGY_H

#include "itravel_strategy.h"

typedef struct _TrainStrategy TrainStrategy;

struct _TrainStrategy
{
	union
	{
		ITravelStrategy;
		ITravelStrategy itravelStrategy;
	};
};

extern TrainStrategy* TrainStrategy_construct(void*);
extern void TrainStrategy_destruct(TrainStrategy*);

#endif
