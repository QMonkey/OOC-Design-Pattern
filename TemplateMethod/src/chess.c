#include <stdio.h>

#include "igame.h"
#include "abstract_game.h"
#include "chess.h"

static void Chess_initialize(IGame*);
static void Chess_end(IGame*);

Chess* constructChess(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	Chess* chess = addr;

	constructAbstractGame(&chess->abstractGame);
	chess->initialize = Chess_initialize;
	chess->end = Chess_end;

	return chess;
}

void destructChess(Chess* chess)
{
}

void Chess_initialize(IGame* igame)
{
	printf("Initialize chess!\n");
}

void Chess_end(IGame* igame)
{
	printf("End chess!\n");
}
