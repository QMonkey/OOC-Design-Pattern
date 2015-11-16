#ifndef WHEEL_H
#define WHEEL_H

#include "icar_element.h"

typedef struct _Wheel Wheel;

struct _Wheel
{
	union
	{
		ICarElement;
		ICarElement icarElement;
	};
};

extern Wheel* Wheel_construct(void*);
extern void Wheel_destruct(Wheel*);

#endif
