#include <stdio.h>

#include "singleton.h"

int main()
{
	Singleton* singleton = getSingleton();
	printf("%lu\n", singleton->currentTime);

	singleton = getSingleton();
	printf("%lu\n", singleton->currentTime);

	return 0;
}
