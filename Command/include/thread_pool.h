#ifndef THREAD_POOL_H
#define THREAD_POOL_H

#include <pthread.h>

#include "icommand.h"
#include "iblockingqueue.h"

typedef struct _ThreadPool ThreadPool;

struct _ThreadPool
{
	int isStop;
	int threadCount;
	pthread_t *tids;
	size_t tidSize;
	IBlockingQueue *iblockingQueue;

	void (*setThreadCount)(ThreadPool*, int);
	void (*start)(ThreadPool*);
	void (*stop)(ThreadPool*);
	void (*execute)(ThreadPool*, ICommand*);
};

extern ThreadPool* constructThreadPool(void*, int);
extern void destructThreadPool(ThreadPool*);

#endif
