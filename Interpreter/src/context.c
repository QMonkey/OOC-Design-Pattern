#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "base.h"
#include "iexpression.h"
#include "plus.h"
#include "minus.h"
#include "multiply.h"
#include "divide.h"
#include "number.h"
#include "context.h"

static int Context_calculate(Context*, char*);

Context* Context_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	Context* context = addr;
	context->expressions = NULL;
	context->count = context->size = 0;

	context->calculate = Context_calculate;

	return context;
}

void Context_destruct(Context* context)
{
	// TODO delete
}

int Context_calculate(Context* context, char* suffixExpression)
{
	char* suffix = strdup(suffixExpression);
	char* token = strtok(suffix, " ");
	while (token != NULL)
	{
		token += strspn(token, " ");

		char first = token[0];
		if (first == '+' || first == '-' || first == '*' || first == '/')
		{
			if (context->count < 2)
			{
				fprintf(stderr, "No enough operations for '%s'.\n", token);
				abort();
			}

			IExpression* rightExpression = context->expressions[--context->count];
			IExpression* leftExpression = context->expressions[--context->count];

			if (strcmp(token, "+") == 0)
			{
				context->expressions[context->count++] = &new (Plus, leftExpression, rightExpression)->iexpression;
			}
			else if (strcmp(token, "-") == 0)
			{
				context->expressions[context->count++] = &new (Minus, leftExpression, rightExpression)->iexpression;
			}
			else if (strcmp(token, "*") == 0)
			{
				context->expressions[context->count++] = &new (Multiply, leftExpression, rightExpression)->iexpression;
			}
			else if (strcmp(token, "/") == 0)
			{
				context->expressions[context->count++] = &new (Divide, leftExpression, rightExpression)->iexpression;
			}
			else
			{
				fprintf(stderr, "Invalid operator '%s'.\n", token);
				abort();
			}
		}
		else
		{
			if (context->count == context->size)
			{
				context->size <<= 1;
				IExpression** expressions = malloc(sizeof(IExpression*) * context->size);
				memcpy(expressions, context->expressions, context->count * sizeof(IExpression*));
				// TODO delete
				context->expressions = expressions;
			}

			context->expressions[context->count++] = &new (Number, token)->iexpression;
		}

		token = strtok(NULL, " ");
	}

	if (context->count != 1)
	{
		fprintf(stderr, "Invalid expression '%s', count=%lu! \n", suffix, context->count);
		abort();
	}

	int result = context->expressions[0]->interpret(context->expressions[0]);

	// TODO delete
	free(suffix);
	context->count = 0;

	return result;
}
