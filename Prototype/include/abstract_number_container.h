#ifndef ABSTRACT_NUMBER_CONTAINER_H
#define ABSTRACT_NUMBER_CONTAINER_H

#include <stddef.h>

#include "iclone.h"

typedef struct _AbstractNumberContainer AbstractNumberContainer;

struct _AbstractNumberContainer
{
	int* container;
	size_t idx;
	size_t size;

	void (*addNumber)(AbstractNumberContainer*, int);
	void (*foreach)(AbstractNumberContainer*, void (*)(int));
	int (*align)(AbstractNumberContainer*, int);
	union
	{
		IClone;
		IClone iclone;
	};
};

extern void AbstractNumberContainer_construct(void*, int);
extern void AbstractNumberContainer_destruct(AbstractNumberContainer*);

#endif
