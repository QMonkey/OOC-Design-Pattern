#ifndef DOTA2_H
#define DOTA2_H

#include "igame.h"
#include "abstract_game.h"

typedef struct _Dota2 Dota2;

struct _Dota2
{
	union
	{
		AbstractGame;
		AbstractGame abstractGame;
	};
};

extern Dota2* constructDota2(void* addr);
extern void destructDota2(Dota2*);

#endif
