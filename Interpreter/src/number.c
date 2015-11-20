#include <stdio.h>
#include <stdlib.h>

#include "base.h"
#include "iexpression.h"
#include "number.h"

static int Number_interpret(IExpression*);

Number* Number_construct(void* addr, char* num)
{
	if (addr == NULL)
	{
		return NULL;
	}

	Number* number = addr;
	number->value = atoi(num);

	number->interpret = Number_interpret;

	return number;
}

void Number_destruct(Number* number)
{
}

int Number_interpret(IExpression* iexpression)
{
	Number* number = container_of(iexpression, Number, iexpression);
	return number->value;
}
