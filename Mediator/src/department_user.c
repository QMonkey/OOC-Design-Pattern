#include <stdio.h>

#include "department_user.h"

static int DepartmentUser_getDepartmentId(DepartmentUser*);
static int DepartmentUser_getUserId(DepartmentUser*);

DepartmentUser* DepartmentUser_construct(void* addr, int departmentId, int userId)
{
	if (addr == NULL)
	{
		return NULL;
	}

	DepartmentUser* departmentUser = addr;
	departmentUser->departmentId = departmentId;
	departmentUser->userId = userId;

	departmentUser->getDepartmentId = DepartmentUser_getDepartmentId;
	departmentUser->getUserId = DepartmentUser_getUserId;

	return departmentUser;
}

void DepartmentUser_destruct(DepartmentUser* departmentUser)
{
}

int DepartmentUser_getDepartmentId(DepartmentUser* departmentUser)
{
	return departmentUser->departmentId;
}

int DepartmentUser_getUserId(DepartmentUser* departmentUser)
{
	return departmentUser->userId;
}
