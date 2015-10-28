#ifndef PRODUCER_H
#define PRODUCER_H

#include "icar.h"
#include "ibuilder.h"

typedef struct _Producer Producer;

struct _Producer
{
	IBuilder* builder;

	void (*setBuilder)(Producer*, IBuilder*);
	ICar* (*produce)(Producer*);
};

extern Producer* Producer_construct(void*, IBuilder*);
extern void Producer_destruct(Producer*);

#endif
