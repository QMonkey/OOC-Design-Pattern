#ifndef COMPUTER_FACADE_H
#define COMPUTER_FACADE_H

#include "cpu.h"
#include "memory.h"
#include "harddrive.h"

typedef struct _ComputerFacade ComputerFacade;

struct _ComputerFacade
{
	CPU* cpu;
	Memory* memory;
	HardDrive* harddrive;

	void (*start)(ComputerFacade*);
};

extern ComputerFacade* ComputerFacade_construct(void*);
extern void ComputerFacade_destruct(ComputerFacade*);

#endif
