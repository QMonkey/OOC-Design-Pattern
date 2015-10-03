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

extern AirplaneStrategy* constructAirplaneStrategy(void*);
extern void destructAirplaneStrategy(AirplaneStrategy*);

#endif
