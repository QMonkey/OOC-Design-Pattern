#include <stdio.h>

#include "base.h"
#include "iexpression.h"
#include "multiply.h"

static int Multiply_interpret(IExpression*);

Multiply* Multiply_construct(void* addr, IExpression* leftExpression, IExpression* rightExpression)
{
	if (addr == NULL)
	{
		return NULL;
	}

	Multiply* multiply = addr;
	multiply->leftExpression = leftExpression;
	multiply->rightExpression = rightExpression;

	multiply->interpret = Multiply_interpret;

	return multiply;
}

void Multiply_destruct(Multiply* multiply)
{
}

int Multiply_interpret(IExpression* iexpression)
{
	Multiply* multiply = container_of(iexpression, Multiply, iexpression);
	return multiply->leftExpression->interpret(multiply->leftExpression) * multiply->rightExpression->interpret(multiply->rightExpression);
}
