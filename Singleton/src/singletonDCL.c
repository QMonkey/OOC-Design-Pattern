#include <sys/time.h>
#include <pthread.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "base.h"
#include "singleton.h"

static Singleton* Singleton_construct(void* addr);

static pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
static volatile int isInit = 0;
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
	if (!isInit)
	{
		int errCode = pthread_mutex_lock(&mutex);
		if (errCode)
		{
			fprintf(stderr, "pthread_mutex_lock error. [err=%s]",
				strerror(errCode));
			abort();
		}

		if (!isInit)
		{
			singleton = new (Singleton);
			if (singleton == NULL)
			{
				fprintf(stderr, "Fail to new singleton.\n");
				abort();
			}
		}
		isInit = 1;

		errCode = pthread_mutex_unlock(&mutex);
		if (errCode)
		{
			fprintf(stderr, "pthread_mutex_unlock error. [err=%s]",
				strerror(errCode));
			abort();
		}
	}

	return singleton;
}
