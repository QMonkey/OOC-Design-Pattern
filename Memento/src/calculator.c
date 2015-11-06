#include <stdio.h>

#include "base.h"
#include "iclone.h"
#include "imemento.h"
#include "calculator.h"

typedef struct _CalculatorMemento CalculatorMemento;

struct _CalculatorMemento
{
	Calculator* calculator;

	union
	{
		IMemento;
		IMemento imemento;
	};
};

static CalculatorMemento* CalculatorMemento_construct(void* addr, Calculator* calculator);
static void CalculatorMemento_destruct(CalculatorMemento*);
static Calculator* CalculatorMemento_getMemento(CalculatorMemento*);

static IClone* Calculator_clone(IClone*);
static void Calculator_add(Calculator*, int, int);
static void Calculator_minus(Calculator*, int, int);
static int Calculator_getResult(Calculator*);
static IMemento* Calculator_createMemento(Calculator*);
static void Calculator_setMemento(Calculator*, IMemento*);

Calculator* Calculator_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	Calculator* calculator = addr;

	calculator->clone = Calculator_clone;
	calculator->add = Calculator_add;
	calculator->minus = Calculator_minus;
	calculator->getResult = Calculator_getResult;
	calculator->createMemento = Calculator_createMemento;
	calculator->setMemento = Calculator_setMemento;

	return calculator;
}

IClone* Calculator_clone(IClone* iclone)
{
	Calculator* calculator = container_of(iclone, Calculator, iclone);
	Calculator* newCalculator = new (Calculator);
	newCalculator->result = calculator->result;
	return &newCalculator->iclone;
}

void Calculator_destruct(Calculator* calculator)
{
}

void Calculator_add(Calculator* calculator, int a, int b)
{
	calculator->result = a + b;
}

void Calculator_minus(Calculator* calculator, int a, int b)
{
	calculator->result = a - b;
}

int Calculator_getResult(Calculator* calculator)
{
	return calculator->result;
}

IMemento* Calculator_createMemento(Calculator* calculator)
{
	IClone* backup = calculator->clone(&calculator->iclone);
	Calculator* newCalculator = container_of(backup, Calculator, iclone);
	return &new (CalculatorMemento, newCalculator)->imemento;
}

void Calculator_setMemento(Calculator* calculator, IMemento* memento)
{
	CalculatorMemento* calculatorMemento = container_of(memento, CalculatorMemento, imemento);
	calculator->result = CalculatorMemento_getMemento(calculatorMemento)->result;
}

CalculatorMemento* CalculatorMemento_construct(void* addr, Calculator* calculator)
{
	if (addr == NULL)
	{
		return NULL;
	}

	CalculatorMemento* calculatorMemento = addr;
	calculatorMemento->calculator = calculator;

	return calculatorMemento;
}

void CalculatorMemento_destruct(CalculatorMemento* calculatorMemento)
{
}

Calculator* CalculatorMemento_getMemento(CalculatorMemento* calculatorMemento)
{
	return calculatorMemento->calculator;
}
