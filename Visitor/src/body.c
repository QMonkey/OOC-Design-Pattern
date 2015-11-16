#include <stdio.h>

#include "base.h"
#include "icar_element.h"
#include "icar_element_visitor.h"
#include "body.h"

static char* Body_getName(ICarElement*);
static void Body_accept(ICarElement*, ICarElementVisitor*);

Body* Body_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	Body* body = addr;

	body->getName = Body_getName;
	body->accept = Body_accept;

	return body;
}

void Body_destruct(Body* body)
{
}

char* Body_getName(ICarElement* icarElement)
{
	return "Body";
}

void Body_accept(ICarElement* icarElement, ICarElementVisitor* carElementVisitor)
{
	Body* body = container_of(icarElement, Body, icarElement);
	carElementVisitor->visitBody(carElementVisitor, body);
}
