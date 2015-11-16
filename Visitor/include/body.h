#ifndef BODY_H
#define BODY_H

#include "icar_element.h"

typedef struct _Body Body;

struct _Body
{
	union
	{
		ICarElement;
		ICarElement icarElement;
	};
};

extern Body* Body_construct(void*);
extern void Body_destruct(Body*);

#endif
