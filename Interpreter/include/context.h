#ifndef CONTEXT_H
#define CONTEXT_H

#include <stddef.h>

#include "iexpression.h"

typedef struct _Context Context;

struct _Context
{
	IExpression** expressions;
	size_t count;
	size_t size;

	int (*calculate)(Context*, char*);
};

extern Context* Context_construct(void*);
extern void Context_destruct(Context*);

#endif
