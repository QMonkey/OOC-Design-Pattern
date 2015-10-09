#ifndef ABSTRACT_GAME_H
#define ABSTRACT_GAME_H

#include "igame.h"

typedef struct _AbstractGame AbstractGame;

struct _AbstractGame
{
	int playerCount;

	void (*play)(AbstractGame*, int);
	union
	{
		IGame;
		IGame igame;
	};
};

extern void constructAbstractGame(void*);
extern void destructAbstractGame(AbstractGame*);

#endif
