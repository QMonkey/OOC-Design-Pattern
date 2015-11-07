#include <stdio.h>

#include "department.h"

static int Department_getId(Department*);
static char* Department_getName(Department*);
static void Department_setName(Department*, char*);
static void Department_del(Department*);

Department* Department_construct(void* addr, Mediator* mediator, int id, char* name)
{
	if (addr == NULL)
	{
		return NULL;
	}

	Department* department = addr;
	department->mediator = mediator;
	department->id = id;
	department->name = name;

	department->getId = Department_getId;
	department->getName = Department_getName;
	department->setName = Department_setName;
	department->del = Department_del;

	return department;
}

void Department_destruct(Department* department)
{
}

int Department_getId(Department* department)
{
	return department->id;
}

char* Department_getName(Department* department)
{
	return department->name;
}

void Department_setName(Department* department, char* name)
{
	department->name = name;
}

void Department_del(Department* department)
{
	department->mediator->delByDepartmentId(department->mediator, department->id);
}
