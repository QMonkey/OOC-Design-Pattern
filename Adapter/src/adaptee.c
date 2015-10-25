#include <stdio.h>

#include "iadaptee.h"
#include "adaptee.h"

static long Adaptee_power(IAdaptee*, int, int);

Adaptee* Adaptee_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	Adaptee* adaptee = addr;
	adaptee->power = Adaptee_power;

	return adaptee;
}

void Adaptee_destruct(Adaptee* adaptee)
{
}

long Adaptee_power(IAdaptee* iadaptee, int base, int exp)
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
		sum *= base;
	}

	return sum;
}
