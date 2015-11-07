#include <stdio.h>

#include "user.h"

static int User_getId(User*);
static char* User_getName(User*);
static void User_setName(User*, char*);
static void User_del(User*);

User* User_construct(void* addr, Mediator* mediator, int id, char* name)
{
	if (addr == NULL)
	{
		return NULL;
	}

	User* user = addr;
	user->mediator = mediator;
	user->id = id;
	user->name = name;

	user->getId = User_getId;
	user->getName = User_getName;
	user->setName = User_setName;
	user->del = User_del;

	return user;
}

void User_destruct(User* user)
{
}

int User_getId(User* user)
{
	return user->id;
}

char* User_getName(User* user)
{
	return user->name;
}

void User_setName(User* user, char* name)
{
	user->name = name;
}

void User_del(User* user)
{
	user->mediator->delByUserId(user->mediator, user->id);
}
