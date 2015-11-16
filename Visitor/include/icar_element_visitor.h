#ifndef ICAR_ELEMENT_VISITOR_H
#define ICAR_ELEMENT_VISITOR_H

#include "wheel.h"
#include "engine.h"
#include "body.h"

typedef struct _ICarElementVisitor ICarElementVisitor;

struct _ICarElementVisitor
{
	void (*visitWheel)(ICarElementVisitor*, Wheel*);
	void (*visitEngine)(ICarElementVisitor*, Engine*);
	void (*visitBody)(ICarElementVisitor*, Body*);
};

#endif
