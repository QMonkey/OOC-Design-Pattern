#include <stdio.h>

#include "memory.h"

static void Memory_load(Memory*, long);

Memory* Memory_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	Memory* memory = addr;
	memory->load = Memory_load;

	return memory;
}

void Memory_destruct(Memory* memory)
{
}

void Memory_load(Memory* memory, long position)
{
	printf("Memory load from position %ld!\n", position);
}
