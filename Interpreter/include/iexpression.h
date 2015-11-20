#ifndef IEXPRESSION_H
#define IEXPRESSION_H

typedef struct _IExpression IExpression;

struct _IExpression
{
	int (*interpret)(IExpression*);
};

#endif
