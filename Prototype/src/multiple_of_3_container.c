#include <stdio.h>
#include <string.h>

#include "base.h"
#include "iclone.h"
#include "abstract_number_container.h"
#include "multiple_of_3_container.h"

static IClone* MultipleOf3Container_clone(IClone*);
static int MultipleOf3Container_align(AbstractNumberContainer*, int);

MultipleOf3Container* MultipleOf3Container_construct(void* addr, int size)
{
	if (addr == NULL)
	{
		return NULL;
	}

	MultipleOf3Container* multipleOf3Container = addr;
	AbstractNumberContainer_construct(&multipleOf3Container->abstractNumberContainer, size);

	multipleOf3Container->clone = MultipleOf3Container_clone;
	multipleOf3Container->align = MultipleOf3Container_align;

	return multipleOf3Container;
}

void MultipleOf3Container_destruct(MultipleOf3Container* multipleOf3Container)
{
	AbstractNumberContainer_destruct(&multipleOf3Container->abstractNumberContainer);
}

IClone* MultipleOf3Container_clone(IClone* iclone)
{
	MultipleOf3Container* multipleOf3Container = container_of(iclone, MultipleOf3Container, iclone);
	MultipleOf3Container* newContainer = new (MultipleOf3Container, multipleOf3Container->size);
	memcpy(newContainer->container, multipleOf3Container->container, sizeof(int) * multipleOf3Container->idx);
	newContainer->idx = multipleOf3Container->idx;
	return &newContainer->iclone;
}

int MultipleOf3Container_align(AbstractNumberContainer* abstractNumberContainer, int number)
{
	number = number + 2;
	return number - number % 3;
}
