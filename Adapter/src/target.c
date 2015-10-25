#include <stdio.h>

#include "itarget.h"
#include "target.h"

static long Target_powerOf2(ITarget*, int);

Target* Target_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	Target* target = addr;
	target->powerOf2 = Target_powerOf2;

	return target;
}

void Target_destruct(Target* target)
{
}

long Target_powerOf2(ITarget* itarget, int exp)
{
	if (exp < 0)
	{
		fprintf(stderr, "Do not support negative exponent.\n");
		return -1;
	}

	if (exp == 0)
	{
		return 1;
	}

	long sum = 1;
	while (exp--)
	{
		sum <<= 1;
	}

	return sum;
}
