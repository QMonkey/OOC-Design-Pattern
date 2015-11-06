#include <stdio.h>

#include "base.h"
#include "imanager.h"
#include "abstract_manager.h"
#include "project_manager.h"

static int ProjecttManager_handleAskForLeaveRequest(IManager*, char*, int);
static int ProjectManager_handleRaisesRequest(IManager*, char*, int);

ProjectManager* ProjectManager_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	ProjectManager* projectManager = addr;
	AbstractManager_construct(&projectManager->abstractManager);

	projectManager->handleAskForLeaveRequest = ProjecttManager_handleAskForLeaveRequest;
	projectManager->handleRaisesRequest = ProjectManager_handleRaisesRequest;

	return projectManager;
}

void ProjectManager_destruct(ProjectManager* projectManager)
{
	AbstractManager_destruct(&projectManager->abstractManager);
}

int ProjecttManager_handleAskForLeaveRequest(IManager* imanager, char* name, int days)
{
	if (days < 7)
	{
		printf("%s's %d days leave request is allowed by project manager!\n", name, days);
		return 1;
	}

	ProjectManager* projectManager = container_of(imanager, ProjectManager, imanager);
	if (projectManager->nextManager == NULL)
	{
		fprintf(stderr, "No next manager!\n");
		return 0;
	}

	return projectManager->nextManager->handleAskForLeaveRequest(projectManager->nextManager, name, days);
}

int ProjectManager_handleRaisesRequest(IManager* imanager, char* name, int money)
{
	if (money > 10000)
	{
		printf("%s's %d raises request is not allowed by project manager!\n", name, money);
		return 0;
	}

	printf("%s's %d raises request is allowed by project manager!\n", name, money);

	ProjectManager* projectManager = container_of(imanager, ProjectManager, imanager);
	if (projectManager->nextManager != NULL)
	{
		return projectManager->nextManager->handleRaisesRequest(projectManager->nextManager, name, money);
	}

	return 1;
}
