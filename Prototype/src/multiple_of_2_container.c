#include <stdio.h>
#include <string.h>

#include "base.h"
#include "iclone.h"
#include "abstract_number_container.h"
#include "multiple_of_2_container.h"

static IClone* MultipleOf2Container_clone(IClone*);
static int MultipleOf2Container_align(AbstractNumberContainer*, int);

MultipleOf2Container* MultipleOf2Container_construct(void* addr, int size)
{
	if (addr == NULL)
	{
		return NULL;
	}

	MultipleOf2Container* multipleOf2Container = addr;
	AbstractNumberContainer_construct(&multipleOf2Container->abstractNumberContainer, size);

	multipleOf2Container->clone = MultipleOf2Container_clone;
	multipleOf2Container->align = MultipleOf2Container_align;

	return multipleOf2Container;
}

void MultipleOf2Container_destruct(MultipleOf2Container* multipleOf2Container)
{
	AbstractNumberContainer_destruct(&multipleOf2Container->abstractNumberContainer);
}

IClone* MultipleOf2Container_clone(IClone* iclone)
{
	MultipleOf2Container* multipleOf2Container = container_of(iclone, MultipleOf2Container, iclone);
	MultipleOf2Container* newContainer = new (MultipleOf2Container, multipleOf2Container->size);
	memcpy(newContainer->container, multipleOf2Container->container, sizeof(int) * multipleOf2Container->idx);
	newContainer->idx = multipleOf2Container->idx;
	return &newContainer->iclone;
}

int MultipleOf2Container_align(AbstractNumberContainer* abstractNumberContainer, int number)
{
	return (number + 1) & 0xfffffffe;
}
