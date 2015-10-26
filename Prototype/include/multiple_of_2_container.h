#ifndef MULTIPLE_OF_2_CONTAINER_H
#define MULTIPLE_OF_2_CONTAINER_H

#include "abstract_number_container.h"

typedef struct _MultipleOf2Container MultipleOf2Container;

struct _MultipleOf2Container
{
	union
	{
		AbstractNumberContainer;
		AbstractNumberContainer abstractNumberContainer;
	};
};

extern MultipleOf2Container* MultipleOf2Container_construct(void*, int);
extern void MultipleOf2Container_destruct(MultipleOf2Container*);

#endif
