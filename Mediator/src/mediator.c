#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "base.h"
#include "department_user.h"
#include "mediator.h"

static void Mediator_addRelation(Mediator*, int, int);
static void Mediator_delByDepartmentId(Mediator*, int);
static void Mediator_delByUserId(Mediator*, int);

Mediator* Mediator_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	Mediator* mediator = addr;
	mediator->departmentUsers = malloc(sizeof(DepartmentUser*));
	mediator->departmentUsers[0] = NULL;
	mediator->count = 0;
	mediator->size = 1;

	mediator->addRelation = Mediator_addRelation;
	mediator->delByDepartmentId = Mediator_delByDepartmentId;
	mediator->delByUserId = Mediator_delByUserId;

	return mediator;
}

void Mediator_destruct(Mediator* mediator)
{
	int i;
	for (i = 0; i < mediator->count; ++i)
	{
		delete (DepartmentUser, mediator->departmentUsers[i]);
	}
	free(mediator->departmentUsers);
}

void Mediator_addRelation(Mediator* mediator, int departmentId, int userId)
{
	if (mediator->count == mediator->size)
	{
		mediator->size <<= 1;
		DepartmentUser** tmp = malloc(sizeof(DepartmentUser*) * mediator->size);
		memcpy(tmp, mediator->departmentUsers, mediator->count * sizeof(DepartmentUser*));
		free(mediator->departmentUsers);
		mediator->departmentUsers = tmp;
	}

	DepartmentUser* departmentUser = new (DepartmentUser, departmentId, userId);
	mediator->departmentUsers[mediator->count++] = departmentUser;
}

void Mediator_delByDepartmentId(Mediator* mediator, int id)
{
	int i;
	for (i = 0; i < mediator->count;)
	{
		DepartmentUser* departmentUser = mediator->departmentUsers[i];
		if (departmentUser->getDepartmentId(departmentUser) == id)
		{
			delete (DepartmentUser, departmentUser);
			memmove(mediator->departmentUsers + i, mediator->departmentUsers + i + 1, sizeof(DepartmentUser*) * (--mediator->count - i));
			continue;
		}
		++i;
	}
}

void Mediator_delByUserId(Mediator* mediator, int id)
{
	int i;
	for (i = 0; i < mediator->count;)
	{
		DepartmentUser* departmentUser = mediator->departmentUsers[i];
		if (departmentUser->getUserId(departmentUser) == id)
		{
			delete (DepartmentUser, departmentUser);
			memmove(mediator->departmentUsers + i, mediator->departmentUsers + i + 1, sizeof(DepartmentUser*) * (--mediator->count - i));
			continue;
		}
		++i;
	}
}
