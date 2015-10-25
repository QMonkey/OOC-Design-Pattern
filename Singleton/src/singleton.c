#include <sys/time.h>
#include <pthread.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "base.h"
#include "singleton.h"

static Singleton* Singleton_construct(void* addr);

static pthread_once_t once_control = PTHREAD_ONCE_INIT;
static Singleton* singleton = NULL;

Singleton* Singleton_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	struct timeval tv;
	int errCode = gettimeofday(&tv, NULL);
	if (errCode)
	{
		fprintf(stderr, "gettimeofday error. [err=%s]",
			strerror(errCode));
		abort();
	}

	Singleton* singleton = addr;
	singleton->currentTime = tv.tv_sec * 1000000 + tv.tv_usec;

	return singleton;
}

Singleton* getSingleton()
{
	void init()
	{
		singleton = new (Singleton);
		if (singleton == NULL)
		{
			fprintf(stderr, "Fail to new singleton.\n");
			abort();
		}
	}

	int errCode = pthread_once(&once_control, init);
	if (errCode)
	{
		fprintf(stderr, "pthread_once error. [err=%s]",
			strerror(errCode));
		abort();
	}

	return singleton;
}
