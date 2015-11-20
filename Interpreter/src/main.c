#include <stdio.h>

#include "base.h"
#include "context.h"

int main()
{
	Context* context = new (Context);

	printf("%d\n", context->calculate(context, "1 1 + 2 * 3 4 5 + - *"));
	printf("%d\n", context->calculate(context, "1 2 + 3 + 4 + 5 + 6 +"));
	printf("%d\n", context->calculate(context, "1 2 * 3 * 4 * 5 * 6 *"));
	printf("%d\n", context->calculate(context, "10000 2 / 2 / 2 / 2 / 2 /"));

	delete (Context, context);
	return 0;
}
