#ifndef NUMBER_H
#define NUMBER_H

#include "iexpression.h"

typedef struct _Number Number;

struct _Number
{
	int value;

	union
	{
		IExpression;
		IExpression iexpression;
	};
};

extern Number* Number_construct(void*, char*);
extern void Number_destruct(Number*);

#endif
