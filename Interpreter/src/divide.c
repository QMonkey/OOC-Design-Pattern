#include <stdio.h>

#include "base.h"
#include "iexpression.h"
#include "divide.h"

static int Divide_interpret(IExpression*);

Divide* Divide_construct(void* addr, IExpression* leftExpression, IExpression* rightExpression)
{
	if (addr == NULL)
	{
		return NULL;
	}

	Divide* divide = addr;
	divide->leftExpression = leftExpression;
	divide->rightExpression = rightExpression;

	divide->interpret = Divide_interpret;

	return divide;
}

void Divide_destruct(Divide* divide)
{
}

int Divide_interpret(IExpression* iexpression)
{
	Divide* divide = container_of(iexpression, Divide, iexpression);
	return divide->leftExpression->interpret(divide->leftExpression) / divide->rightExpression->interpret(divide->rightExpression);
}
