#ifndef CHESS_H
#define CHESS_H

#include "igame.h"
#include "abstract_game.h"

typedef struct _Chess Chess;

struct _Chess
{
	union
	{
		AbstractGame;
		AbstractGame abstractGame;
	};
};

extern Chess* constructChess(void*);
extern void destructChess(Chess*);

#endif
