#ifndef PROJECT_MANAGER_H
#define PROJECT_MANAGER_H

#include "abstract_manager.h"

typedef struct _ProjectManager ProjectManager;

struct _ProjectManager
{
	union
	{
		AbstractManager;
		AbstractManager abstractManager;
	};
};

extern ProjectManager* ProjectManager_construct(void*);
extern void ProjectManager_destruct(ProjectManager*);

#endif
