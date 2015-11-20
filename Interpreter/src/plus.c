#include <stdio.h>

#include "base.h"
#include "iexpression.h"
#include "plus.h"

static int Plus_interpret(IExpression*);

Plus* Plus_construct(void* addr, IExpression* leftExpression, IExpression* rightExpression)
{
	if (addr == NULL)
	{
		return NULL;
	}

	Plus* plus = addr;
	plus->leftExpression = leftExpression;
	plus->rightExpression = rightExpression;

	plus->interpret = Plus_interpret;

	return plus;
}

void Plus_destruct(Plus* plus)
{
}

int Plus_interpret(IExpression* iexpression)
{
	Plus* plus = container_of(iexpression, Plus, iexpression);
	return plus->leftExpression->interpret(plus->leftExpression) + plus->rightExpression->interpret(plus->rightExpression);
}
