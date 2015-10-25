#ifndef CPU_H
#define CPU_H

typedef struct _CPU CPU;

struct _CPU
{
	void (*freeze)(CPU*);
	void (*jump)(CPU*, long);
	void (*execute)(CPU*);
};

extern CPU* CPU_construct(void*);
extern void CPU_destruct(CPU*);

#endif
