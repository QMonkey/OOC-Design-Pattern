#ifndef MEDIATOR_H
#define MEDIATOR_H

#include <stddef.h>

#include "department_user.h"

typedef struct _Mediator Mediator;

struct _Mediator
{
	DepartmentUser** departmentUsers;
	size_t count;
	size_t size;

	void (*addRelation)(Mediator*, int, int);
	void (*delByDepartmentId)(Mediator*, int);
	void (*delByUserId)(Mediator*, int);
};

extern Mediator* Mediator_construct(void*);
extern void Mediator_destruct(Mediator*);

#endif
