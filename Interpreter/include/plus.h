#ifndef PLUS_H
#define PLUS_H

#include "iexpression.h"

typedef struct _Plus Plus;

struct _Plus
{
	IExpression* leftExpression;
	IExpression* rightExpression;

	union
	{
		IExpression;
		IExpression iexpression;
	};
};

extern Plus* Plus_construct(void*, IExpression*, IExpression*);
extern void Plus_destruct(Plus*);

#endif
