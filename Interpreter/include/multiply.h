#ifndef MULTIPLY_H
#define MULTIPLY_H

#include "iexpression.h"

typedef struct _Multiply Multiply;

struct _Multiply
{
	IExpression* leftExpression;
	IExpression* rightExpression;

	union
	{
		IExpression;
		IExpression iexpression;
	};
};

extern Multiply* Multiply_construct(void*, IExpression*, IExpression*);
extern void Multiply_destruct(Multiply*);

#endif
