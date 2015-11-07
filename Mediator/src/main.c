#include <stdio.h>
#include <stddef.h>

#include "base.h"
#include "user.h"
#include "department.h"
#include "department_user.h"
#include "mediator.h"

void printRelation(DepartmentUser** departmentUsers, size_t size)
{
	int i;
	for (i = 0; i < size; ++i)
	{
		DepartmentUser* departmentUser = departmentUsers[i];
		printf("departmentId: %d\tuserId: %d\n", departmentUser->departmentId, departmentUser->userId);
	}
}

int main()
{
	Mediator* mediator = new (Mediator);
	User* user1 = new (User, mediator, 1, "user1");
	User* user2 = new (User, mediator, 2, "user2");
	User* user3 = new (User, mediator, 3, "user3");
	Department* department1 = new (Department, mediator, 1, "department1");
	Department* department2 = new (Department, mediator, 2, "department2");

	mediator->addRelation(mediator, 1, 1);
	mediator->addRelation(mediator, 2, 1);
	mediator->addRelation(mediator, 3, 1);
	mediator->addRelation(mediator, 1, 2);
	mediator->addRelation(mediator, 2, 2);

	user1->del(user1);
	printRelation(mediator->departmentUsers, mediator->count);
	printf("\n");

	department1->del(department1);
	printRelation(mediator->departmentUsers, mediator->count);

	delete (Department, department1);
	delete (Department, department2);
	delete (User, user1);
	delete (User, user2);
	delete (User, user3);
	delete (Mediator, mediator);
	return 0;
}
