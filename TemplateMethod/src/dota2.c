#include <stdio.h>

#include "igame.h"
#include "abstract_game.h"
#include "dota2.h"

static void Dota2_initialize(IGame*);
static void Dota2_end(IGame*);

Dota2* Dota2_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	Dota2* dota2 = addr;

	AbstractGame_construct(&dota2->abstractGame);
	dota2->initialize = Dota2_initialize;
	dota2->end = Dota2_end;

	return dota2;
}

void Dota2_destruct(Dota2* dota2)
{
}

void Dota2_initialize(IGame* igame)
{
	printf("Initialize dota2!\n");
}

void Dota2_end(IGame* igame)
{
	printf("End dota2!\n");
}
