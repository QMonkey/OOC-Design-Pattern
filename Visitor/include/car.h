#ifndef CAR_H
#define CAR_H

#include "icar_element.h"
#include "icar_element_visitor.h"

typedef struct _Car Car;

struct _Car
{
	ICarElement** elements;

	void (*accept)(Car*, ICarElementVisitor*);
};

extern Car* Car_construct(void*);
extern void Car_destruct(Car*);

#endif
