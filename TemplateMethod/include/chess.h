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

extern Chess* Chess_construct(void*);
extern void Chess_destruct(Chess*);

#endif
