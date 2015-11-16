#ifndef CAR_ELEMENT_RUN_VISITOR_H
#define CAR_ELEMENT_RUN_VISITOR_H

#include "icar_element_visitor.h"

typedef struct _CarElementRunVisitor CarElementRunVisitor;

struct _CarElementRunVisitor
{
	union
	{
		ICarElementVisitor;
		ICarElementVisitor icarElementVisitor;
	};
};

extern CarElementRunVisitor* CarElementRunVisitor_construct(void*);
extern void CarElementRunVisitor_destruct(CarElementRunVisitor*);

#endif
