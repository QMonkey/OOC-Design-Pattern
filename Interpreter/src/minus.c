#include <stdio.h>

#include "base.h"
#include "iexpression.h"
#include "minus.h"

static int Minus_interpret(IExpression*);

Minus* Minus_construct(void* addr, IExpression* leftExpression, IExpression* rightExpression)
{
	if (addr == NULL)
	{
		return NULL;
	}

	Minus* minus = addr;
	minus->leftExpression = leftExpression;
	minus->rightExpression = rightExpression;

	minus->interpret = Minus_interpret;

	return minus;
}

void Minus_destruct(Minus* minus)
{
}

int Minus_interpret(IExpression* iexpression)
{
	Minus* minus = container_of(iexpression, Minus, iexpression);
	return minus->leftExpression->interpret(minus->leftExpression) - minus->rightExpression->interpret(minus->rightExpression);
}
