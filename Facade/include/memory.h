#ifndef MEMORY_H
#define MEMORY_H

typedef struct _Memory Memory;

struct _Memory
{
	void (*load)(Memory*, long);
};

extern Memory* constructMemory(void*);
extern void destructMemory(Memory*);

#endif
