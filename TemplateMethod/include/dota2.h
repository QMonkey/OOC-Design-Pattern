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

extern Dota2* Dota2_construct(void* addr);
extern void Dota2_destruct(Dota2*);

#endif
