#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "base.h"
#include "iclone.h"
#include "abstract_number_container.h"
#include "multiple_of_2_container.h"
#include "multiple_of_3_container.h"

#define CONTAINER_SIZE 10

static AbstractNumberContainer* containers[CONTAINER_SIZE];

void init()
{
	containers[0] = &new (MultipleOf2Container, CONTAINER_SIZE)->abstractNumberContainer;
	containers[1] = &new (MultipleOf3Container, CONTAINER_SIZE)->abstractNumberContainer;
}

void full()
{
	int i, j;
	for (i = 0; i < 2; ++i)
	{
		for (j = 0; j < CONTAINER_SIZE; ++j)
		{
			containers[i]->addNumber(containers[i], rand());
		}
	}

	for (i = 2; i < CONTAINER_SIZE; ++i)
	{
		int idx = i & 1;
		IClone* clone = containers[idx]->clone(&containers[idx]->iclone);
		containers[i] = container_of(clone, AbstractNumberContainer, iclone);
	}
}

void output()
{
	void callback(int number)
	{
		printf("%d ", number);
	}

	int i;
	for (i = 0; i < CONTAINER_SIZE; ++i)
	{
		containers[i]->foreach (containers[i], callback);
		printf("\n");
	}

	// TODO delete
}

int main()
{
	srand(time(NULL));
	init();
	full();
	output();
	return 0;
}
