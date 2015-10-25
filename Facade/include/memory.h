#ifndef MEMORY_H
#define MEMORY_H

typedef struct _Memory Memory;

struct _Memory
{
	void (*load)(Memory*, long);
};

extern Memory* Memory_construct(void*);
extern void Memory_destruct(Memory*);

#endif
