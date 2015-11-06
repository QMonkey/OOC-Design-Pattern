#ifndef CALCULATOR_MEMENTO_MANAGER_H
#define CALCULATOR_MEMENTO_MANAGER_H

#include "imemento.h"

typedef struct _CalculatorMementoManager CalculatorMementoManager;

struct _CalculatorMementoManager
{
	IMemento* memento;

	void (*setMemento)(CalculatorMementoManager*, IMemento*);
	IMemento* (*getMemento)(CalculatorMementoManager*);
};

extern CalculatorMementoManager* CalculatorMementoManager_construct(void*);
extern void CalculatorMementoManager_destruct(CalculatorMementoManager*);

#endif
