#ifndef MULTIPLE_OF_3_CONTAINER_H
#define MULTIPLE_OF_3_CONTAINER_H

#include "abstract_number_container.h"

typedef struct _MultipleOf3Container MultipleOf3Container;

struct _MultipleOf3Container
{
	union
	{
		AbstractNumberContainer;
		AbstractNumberContainer abstractNumberContainer;
	};
};

extern MultipleOf3Container* MultipleOf3Container_construct(void*, int);
extern void MultipleOf3Container_destruct(MultipleOf3Container*);

#endif
