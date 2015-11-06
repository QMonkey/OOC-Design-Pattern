#ifndef HR_H
#define HR_H

#include "abstract_manager.h"

typedef struct _HR HR;

struct _HR
{
	union
	{
		AbstractManager;
		AbstractManager abstractManager;
	};
};

extern HR* HR_construct(void*);
extern void HR_destruct(HR*);

#endif
