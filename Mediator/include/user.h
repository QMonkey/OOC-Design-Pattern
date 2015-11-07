#ifndef USER_H
#define USER_H

#include "mediator.h"

typedef struct _User User;

struct _User
{
	int (*getId)(User*);
	char* (*getName)(User*);
	void (*setName)(User*, char*);
	void (*del)(User*);

	Mediator* mediator;
	int id;
	char* name;
};

extern User* User_construct(void*, Mediator*, int, char*);
extern void User_destruct(User*);

#endif
