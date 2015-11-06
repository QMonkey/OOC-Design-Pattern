#include <stdio.h>

#include "base.h"
#include "imanager.h"
#include "abstract_manager.h"
#include "hr.h"

static int HR_handleAskForLeaveRequest(IManager*, char*, int);
static int HR_handleRaisesRequest(IManager*, char*, int);

HR* HR_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	HR* hr = addr;

	AbstractManager_construct(&hr->abstractManager);
	hr->handleAskForLeaveRequest = HR_handleAskForLeaveRequest;
	hr->handleRaisesRequest = HR_handleRaisesRequest;

	return hr;
}

void HR_destruct(HR* hr)
{
	AbstractManager_destruct(&hr->abstractManager);
}

int HR_handleAskForLeaveRequest(IManager* imanager, char* name, int days)
{
	if (days < 14)
	{
		printf("%s's %d days leave request is allowed by hr!\n", name, days);
		return 1;
	}

	HR* hr = container_of(imanager, HR, imanager);
	if (hr->nextManager == NULL)
	{
		fprintf(stderr, "No next manager!\n");
		return 0;
	}
	return hr->nextManager->handleAskForLeaveRequest(hr->nextManager, name, days);
}

int HR_handleRaisesRequest(IManager* imanager, char* name, int money)
{
	if (money > 7000)
	{
		printf("%s's %d raises request is not allowed by hr!\n", name, money);
		return 0;
	}

	printf("%s's %d raises request is allowed by hr!\n", name, money);

	HR* hr = container_of(imanager, HR, imanager);
	if (hr->nextManager != NULL)
	{
		return hr->nextManager->handleRaisesRequest(hr->nextManager, name, money);
	}

	return 1;
}
