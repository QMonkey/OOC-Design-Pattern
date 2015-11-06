#include <stdio.h>

#include "imemento.h"
#include "calculator_memento_manager.h"

static void CalculatorMementoManager_setMemento(CalculatorMementoManager*, IMemento*);
static IMemento* CalculatorMementoManager_getMemento(CalculatorMementoManager*);

CalculatorMementoManager* CalculatorMementoManager_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	CalculatorMementoManager* calculatorMementoManager = addr;

	calculatorMementoManager->setMemento = CalculatorMementoManager_setMemento;
	calculatorMementoManager->getMemento = CalculatorMementoManager_getMemento;

	return calculatorMementoManager;
}

void CalculatorMementoManager_destruct(CalculatorMementoManager* calculatorMementoManager)
{
	// TODO delete memento
}

void CalculatorMementoManager_setMemento(CalculatorMementoManager* calculatorMementoManager, IMemento* memento)
{
	// TODO delete memento
	calculatorMementoManager->memento = memento;
}

IMemento* CalculatorMementoManager_getMemento(CalculatorMementoManager* calculatorMementoManager)
{
	return calculatorMementoManager->memento;
}
