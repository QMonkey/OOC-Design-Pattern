#include <assert.h>

#include "base.h"
#include "project_manager.h"
#include "hr.h"
#include "boss.h"

int main()
{
	ProjectManager* pm = new (ProjectManager);
	HR* hr = new (HR);
	Boss* boss = new (Boss);

	pm->setManager(&pm->abstractManager, &hr->imanager);
	hr->setManager(&hr->abstractManager, &boss->imanager);

	int result = pm->handleAskForLeaveRequest(&pm->imanager, "QMonkey", 10);
	assert(result == 1);
	result = pm->handleAskForLeaveRequest(&pm->imanager, "QMonkey", 37);
	assert(result == 0);

	result = pm->handleRaisesRequest(&pm->imanager, "QMonkey", 3700);
	assert(result == 1);
	result = pm->handleRaisesRequest(&pm->imanager, "QMonkey", 7700);
	assert(result == 0);

	delete (ProjectManager, pm);
	delete (HR, hr);
	delete (Boss, boss);
	return 0;
}
