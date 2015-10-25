#include <stdio.h>
#include <stdlib.h>

#include "base.h"
#include "cpu.h"
#include "harddrive.h"
#include "memory.h"
#include "computer_facade.h"

static void ComputerFacade_start(ComputerFacade*);

ComputerFacade* ComputerFacade_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	ComputerFacade* computerFacade = addr;
	computerFacade->cpu = new (CPU);
	computerFacade->memory = new (Memory);
	computerFacade->harddrive = new (HardDrive);

	computerFacade->start = ComputerFacade_start;

	return computerFacade;
}

void ComputerFacade_destruct(ComputerFacade* computerFacade)
{
	delete (CPU, computerFacade->cpu);
	delete (Memory, computerFacade->memory);
	delete (HardDrive, computerFacade->harddrive);
}

void ComputerFacade_start(ComputerFacade* computerFacade)
{
	computerFacade->cpu->freeze(computerFacade->cpu);
	computerFacade->harddrive->read(computerFacade->harddrive, rand());
	computerFacade->memory->load(computerFacade->memory, rand());
	computerFacade->cpu->jump(computerFacade->cpu, rand());
	computerFacade->cpu->execute(computerFacade->cpu);
}
