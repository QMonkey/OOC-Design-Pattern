#ifndef MINUS_H
#define MINUS_H

#include "iexpression.h"

typedef struct _Minus Minus;

struct _Minus
{
	IExpression* leftExpression;
	IExpression* rightExpression;

	union
	{
		IExpression;
		IExpression iexpression;
	};
};

extern Minus* Minus_construct(void*, IExpression*, IExpression*);
extern void Minus_destruct(Minus*);

#endif
