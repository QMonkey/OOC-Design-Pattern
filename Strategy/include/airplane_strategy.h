#ifndef AIRPLANE_STRATEGY_H
#define AIRPLANE_STRATEGY_H

#include "itravel_strategy.h"

typedef struct _AirplaneStrategy AirplaneStrategy;

struct _AirplaneStrategy
{
	union
	{
		ITravelStrategy;
		ITravelStrategy itravelStrategy;
	};
};

extern AirplaneStrategy* AirplaneStrategy_construct(void*);
extern void AirplaneStrategy_destruct(AirplaneStrategy*);

#endif
