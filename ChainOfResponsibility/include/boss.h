#ifndef BOSS_H
#define BOSS_H

#include "abstract_manager.h"

typedef struct _Boss Boss;

struct _Boss
{
	union
	{
		AbstractManager;
		AbstractManager abstractManager;
	};
};

extern Boss* Boss_construct(void*);
extern void Boss_destruct(Boss*);

#endif
