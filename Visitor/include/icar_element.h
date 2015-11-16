#ifndef ICAR_ELEMENT_H
#define ICAR_ELEMENT_H

// #include "icar_element_visitor.h"
typedef struct _ICarElementVisitor ICarElementVisitor;

typedef struct _ICarElement ICarElement;

struct _ICarElement
{
	char* (*getName)(ICarElement*);
	void (*accept)(ICarElement*, ICarElementVisitor*);
};

#endif
