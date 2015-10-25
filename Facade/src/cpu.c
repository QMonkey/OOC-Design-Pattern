#include <stdio.h>

#include "cpu.h"

static void CPU_freeze(CPU*);
static void CPU_jump(CPU*, long);
static void CPU_execute(CPU*);

CPU* CPU_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	CPU* cpu = addr;

	cpu->freeze = CPU_freeze;
	cpu->jump = CPU_jump;
	cpu->execute = CPU_execute;

	return cpu;
}

void CPU_destruct(CPU* cpu)
{
}

void CPU_freeze(CPU* cpu)
{
	printf("CPU freeze!\n");
}

void CPU_jump(CPU* cpu, long position)
{
	printf("CPU jump to position %ld!\n", position);
}

void CPU_execute(CPU* cpu)
{
	printf("CPU execute!\n");
}
