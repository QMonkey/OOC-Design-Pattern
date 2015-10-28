#ifndef IBUILDER_H
#define IBUILDER_H

#include "icar.h"

typedef struct _IBuilder IBuilder;

struct _IBuilder
{
	void (*buildBody)(IBuilder*);
	void (*buildEngine)(IBuilder*);
	void (*buildWheel)(IBuilder*);
	ICar* (*getCar)(IBuilder*);
};

#endif
