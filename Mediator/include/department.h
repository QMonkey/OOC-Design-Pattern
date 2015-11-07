#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include "mediator.h"

typedef struct _Department Department;

struct _Department
{
	int (*getId)(Department*);
	char* (*getName)(Department*);
	void (*setName)(Department*, char*);
	void (*del)(Department*);

	Mediator* mediator;
	int id;
	char* name;
};

extern Department* Department_construct(void*, Mediator*, int, char*);
extern void Department_destruct(Department*);

#endif
