#include <stdio.h>
#include <stdlib.h>

#include "base.h"
#include "igame.h"
#include "abstract_game.h"

static void AbstractGame_play(AbstractGame*, int);
static void AbstractGame_initialize(IGame*);
static void AbstractGame_makePlayer(IGame*, int);
static void AbstractGame_end(IGame*);
static void AbstractGame_printWinner(IGame*);

void AbstractGame_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	AbstractGame* abstractGame = addr;
	abstractGame->playerCount = 0;

	abstractGame->play = AbstractGame_play;
	abstractGame->initialize = AbstractGame_initialize;
	abstractGame->makePlayer = AbstractGame_makePlayer;
	abstractGame->end = AbstractGame_end;
	abstractGame->printWinner = AbstractGame_printWinner;
}

void AbstractGame_destruct(AbstractGame* abstractGame)
{
}

void AbstractGame_play(AbstractGame* abstractGame, int playerCount)
{
	abstractGame->initialize(&abstractGame->igame);
	abstractGame->makePlayer(&abstractGame->igame, playerCount);
	abstractGame->end(&abstractGame->igame);
	abstractGame->printWinner(&abstractGame->igame);
}

void AbstractGame_initialize(IGame* igame)
{
	fprintf(stderr, "Not implemented!\n");
	abort();
}

void AbstractGame_makePlayer(IGame* igame, int playerCount)
{
	AbstractGame* abstractGame = container_of(igame, AbstractGame, igame);
	abstractGame->playerCount = playerCount;
}

void AbstractGame_end(IGame* igame)
{
	fprintf(stderr, "Not implemented!\n");
	abort();
}

void AbstractGame_printWinner(IGame* igame)
{
	AbstractGame* abstractGame = container_of(igame, AbstractGame, igame);
	printf("The count of the player is %d. Player 1 is the winner!\n",
	       abstractGame->playerCount);
}
