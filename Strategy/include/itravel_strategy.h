#ifndef ITRAVEL_STRATEGY_H
#define ITRAVEL_STRATEGY_H

typedef struct _ITravelStrategy ITravelStrategy;

struct _ITravelStrategy
{
	void (*travel)(ITravelStrategy*);
};

#endif
