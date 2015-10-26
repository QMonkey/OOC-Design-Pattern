#include <stdio.h>
#include <stdlib.h>

#include "iclone.h"
#include "abstract_number_container.h"

static void AbstractNumberContainer_addNumber(AbstractNumberContainer*, int);
static void AbstractNumberContainer_foreach(AbstractNumberContainer*, void (*)(int));
static int AbstractNumberContainer_align(AbstractNumberContainer*, int);
static IClone* AbstractNumberContainer_clone(IClone*);

void AbstractNumberContainer_construct(void* addr, int size)
{
	if (addr == NULL)
	{
		return NULL;
	}

	AbstractNumberContainer* abstractNumberContainer = addr;
	abstractNumberContainer->container = malloc(sizeof(int) * size);
	if (abstractNumberContainer->container == NULL)
	{
		return;
	}

	abstractNumberContainer->size = size;
	abstractNumberContainer->idx = 0;

	abstractNumberContainer->addNumber = AbstractNumberContainer_addNumber;
	abstractNumberContainer->foreach = AbstractNumberContainer_foreach;
	abstractNumberContainer->align = AbstractNumberContainer_align;
	abstractNumberContainer->clone = AbstractNumberContainer_clone;
}

void AbstractNumberContainer_destruct(AbstractNumberContainer* abstractNumberContainer)
{
	free(abstractNumberContainer->container);
}

void AbstractNumberContainer_addNumber(AbstractNumberContainer* abstractNumberContainer, int number)
{
	abstractNumberContainer->container[abstractNumberContainer->idx++] = abstractNumberContainer->align(abstractNumberContainer, number);
}

void AbstractNumberContainer_foreach(AbstractNumberContainer* abstractNumberContainer, void (*callback)(int))
{
	int i;
	for (i = 0; i < abstractNumberContainer->idx; ++i)
	{
		callback(abstractNumberContainer->container[i]);
	}
}

int AbstractNumberContainer_align(AbstractNumberContainer* abstractNumberContainer, int number)
{
	fprintf(stderr, "Not implemented!\n");
	abort();
	return number;
}

IClone* AbstractNumberContainer_clone(IClone* iclone)
{
	fprintf(stderr, "Not implemented!\n");
	abort();
}
