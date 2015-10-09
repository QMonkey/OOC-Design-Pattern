#ifndef IGAME_H
#define IGAME_H

typedef struct _IGame IGame;

struct _IGame
{
	void (*initialize)(IGame*);
	void (*makePlayer)(IGame*, int);
	void (*end)(IGame*);
	void (*printWinner)(IGame*);
};

#endif
