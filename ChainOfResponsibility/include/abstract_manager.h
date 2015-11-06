#ifndef ABSTRACT_MANAGER_H
#define ABSTRACT_MANAGER_H

#include "imanager.h"

typedef struct _AbstractManager AbstractManager;

struct _AbstractManager
{
	IManager* nextManager;

	void (*setManager)(AbstractManager*, IManager*);
	union
	{
		IManager;
		IManager imanager;
	};
};

extern void AbstractManager_construct(void*);
extern void AbstractManager_destruct(AbstractManager*);

#endif
