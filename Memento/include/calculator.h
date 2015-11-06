#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "iclone.h"
#include "imemento.h"

typedef struct _Calculator Calculator;

struct _Calculator
{
	int result;

	void (*add)(Calculator*, int, int);
	void (*minus)(Calculator*, int, int);
	int (*getResult)(Calculator*);
	IMemento* (*createMemento)(Calculator*);
	void (*setMemento)(Calculator*, IMemento*);
	union
	{
		IClone;
		IClone iclone;
	};
};

extern Calculator* Calculator_construct(void*);
extern void Calculator_destruct(Calculator*);

#endif
