#include <stdio.h>
#include <stdlib.h>

#include "imanager.h"
#include "abstract_manager.h"

static int AbstractManager_handleAskForLeaveRequest(IManager*, char*, int);
static int AbstractManager_handleRaisesRequest(IManager*, char*, int);
static void AbstractManager_setManager(AbstractManager*, IManager*);

void AbstractManager_construct(void* addr)
{
	if (addr == NULL)
	{
		return;
	}

	AbstractManager* abstractManager = addr;
	abstractManager->nextManager = NULL;

	abstractManager->handleAskForLeaveRequest = AbstractManager_handleAskForLeaveRequest;
	abstractManager->handleRaisesRequest = AbstractManager_handleRaisesRequest;
	abstractManager->setManager = AbstractManager_setManager;
}

void AbstractManager_destruct(AbstractManager* abstractManager)
{
}

int AbstractManager_handleAskForLeaveRequest(IManager* imanager, char* name, int days)
{
	fprintf(stderr, "Not implemented!\n");
	abort();
}

int AbstractManager_handleRaisesRequest(IManager* imanager, char* name, int money)
{
	fprintf(stderr, "Not implemented!\n");
	abort();
}

void AbstractManager_setManager(AbstractManager* abstractManager, IManager* manager)
{
	abstractManager->nextManager = manager;
}
