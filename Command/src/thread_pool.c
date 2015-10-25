#include <pthread.h>

#include <stdio.h>
#include <string.h>

#include "base.h"
#include "icommand.h"
#include "iblockingqueue.h"
#include "linked_blockingqueue.h"
#include "thread_pool.h"

static void ThreadPool_setThreadCount(ThreadPool*, int);
static void ThreadPool_start(ThreadPool*);
static void ThreadPool_stop(ThreadPool*);
static void ThreadPool_execute(ThreadPool*, ICommand*);
static void* ThreadPool_run(void* arg);

static void ThreadPool_doNothing()
{
}

static struct
{
	union
	{
		ICommand;
		ICommand icommand;
	};
} stopCommand = {.execute = ThreadPool_doNothing};

ThreadPool* ThreadPool_construct(void* addr, int threadCount)
{
	if (addr == NULL)
	{
		return NULL;
	}

	ThreadPool* threadPool = addr;
	threadPool->isStop = 1;
	threadPool->threadCount = threadCount;
	threadPool->tids = NULL;
	threadPool->tidSize = 0;

	threadPool->blockingQueue = &new (LinkedBlockingQueue)->iblockingQueue;
	if (threadPool->blockingQueue == NULL)
	{
		return NULL;
	}

	threadPool->start = ThreadPool_start;
	threadPool->stop = ThreadPool_stop;
	threadPool->execute = ThreadPool_execute;
	threadPool->setThreadCount = ThreadPool_setThreadCount;

	return threadPool;
}

void ThreadPool_destruct(ThreadPool* threadPool)
{
	LinkedBlockingQueue* linkedBlockingQueue = container_of(
	    threadPool->blockingQueue, LinkedBlockingQueue, iblockingQueue);
	delete (LinkedBlockingQueue, linkedBlockingQueue);
}

void ThreadPool_setThreadCount(ThreadPool* threadPool, int threadCount)
{
	threadPool->threadCount = threadCount;
}

void* ThreadPool_run(void* arg)
{
	ThreadPool* threadPool = arg;
	while (!threadPool->isStop)
	{
		ICommand* command = threadPool->blockingQueue->pop(
		    &threadPool->blockingQueue->iqueue);
		command->execute(command);
	}

	return NULL;
}

void ThreadPool_start(ThreadPool* threadPool)
{
	threadPool->isStop = 0;
	if (threadPool->tidSize < threadPool->threadCount)
	{
		free(threadPool->tids);
		threadPool->tids =
		    malloc(sizeof(pthread_t) * threadPool->threadCount);
		threadPool->tidSize = threadPool->threadCount;
	}

	int i;
	for (i = 0; i < threadPool->threadCount; ++i)
	{
		int err = pthread_create(threadPool->tids + i, NULL,
					 ThreadPool_run, threadPool);
		if (err)
		{
			fprintf(stderr, "pthread_create error. [err=%s]\n",
				strerror(err));
		}
	}
}

void ThreadPool_stop(ThreadPool* threadPool)
{
	threadPool->isStop = 1;

	int i;
	for (i = 0; i < threadPool->threadCount; ++i)
	{
		threadPool->execute(threadPool, &stopCommand.icommand);
	}

	for (i = 0; i < threadPool->tidSize; ++i)
	{
		int err = pthread_join(threadPool->tids[i], NULL);
		if (err)
		{
			fprintf(stderr, "pthread_join error. [err=%s]\n",
				strerror(err));
		}
	}
}

void ThreadPool_execute(ThreadPool* threadPool, ICommand* command)
{
	threadPool->blockingQueue->push(&threadPool->blockingQueue->iqueue,
					command);
}
