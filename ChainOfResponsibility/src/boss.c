#include <stdio.h>

#include "base.h"
#include "imanager.h"
#include "abstract_manager.h"
#include "boss.h"

static int Boss_handleAskForLeaveRequest(IManager*, char*, int);
static int Boss_handleRaisesRequest(IManager*, char*, int);

Boss* Boss_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	Boss* boss = addr;

	AbstractManager_construct(&boss->abstractManager);
	boss->handleAskForLeaveRequest = Boss_handleAskForLeaveRequest;
	boss->handleRaisesRequest = Boss_handleRaisesRequest;

	return boss;
}

void Boss_destruct(Boss* boss)
{
	AbstractManager_destruct(&boss->abstractManager);
}

int Boss_handleAskForLeaveRequest(IManager* imanager, char* name, int days)
{
	if (days < 30)
	{
		printf("%s's %d days leave request is allowed by boss!\n", name, days);
		return 1;
	}

	printf("%s's %d days leave request is not allowed by boss!\n", name, days);
	return 0;
}

int Boss_handleRaisesRequest(IManager* imanager, char* name, int money)
{
	if (money > 5000)
	{
		printf("%s's %d raises request is not allowed by boss!\n", name, money);
		return 0;
	}

	printf("%s's %d raises request is allowed by boss!\n", name, money);
	return 1;
}
