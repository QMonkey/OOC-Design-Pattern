#ifndef DIVIDE_H
#define DIVIDE_H

#include "iexpression.h"

typedef struct _Divide Divide;

struct _Divide
{
	IExpression* leftExpression;
	IExpression* rightExpression;

	union
	{
		IExpression;
		IExpression iexpression;
	};
};

extern Divide* Divide_construct(void*, IExpression*, IExpression*);
extern void Divide_destruct(Divide*);

#endif
