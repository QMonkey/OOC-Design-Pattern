#include <stdio.h>
#include <string.h>

#include "base.h"
#include "icommand.h"
#include "iqueue.h"
#include "iblockingqueue.h"
#include "linkedqueue.h"
#include "linked_blockingqueue.h"

static void LinkedBlockingQueue_push(IQueue*, ICommand*);
static ICommand* LinkedBlockingQueue_pop(IQueue*);
static int LinkedBlockingQueue_empty(IQueue*);

LinkedBlockingQueue* LinkedBlockingQueue_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	LinkedBlockingQueue* linkedBlockingQueue = addr;
	linkedBlockingQueue->queue = &new (LinkedQueue)->iqueue;

	pthread_mutexattr_t attr;
	int err = pthread_mutexattr_init(&attr);
	if (err)
	{
		fprintf(stderr, "pthread_mutexattr_init error. [err=%s]",
			strerror(err));
		return NULL;
	}

	err = pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
	if (err)
	{
		fprintf(stderr, "pthread_mutexattr_settype error. [err=%s]",
			strerror(err));
		return NULL;
	}

	err = pthread_mutex_init(&linkedBlockingQueue->mutex, &attr);
	if (err)
	{
		fprintf(stderr, "pthread_mutex_init error. [err=%s]",
			strerror(err));
		return NULL;
	}

	err = pthread_cond_init(&linkedBlockingQueue->cond, NULL);
	if (err)
	{
		fprintf(stderr, "pthread_cond_init error. [err=%s]",
			strerror(err));
		return NULL;
	}

	linkedBlockingQueue->push = LinkedBlockingQueue_push;
	linkedBlockingQueue->pop = LinkedBlockingQueue_pop;
	linkedBlockingQueue->empty = LinkedBlockingQueue_empty;

	return linkedBlockingQueue;
}

void LinkedBlockingQueue_destruct(LinkedBlockingQueue* linkedBlockingQueue)
{
	int err = pthread_cond_destroy(&linkedBlockingQueue->cond);
	if (err)
	{
		fprintf(stderr, "pthread_cond_destroy error. [err=%s]",
			strerror(err));
	}

	err = pthread_mutex_destroy(&linkedBlockingQueue->mutex);
	if (err)
	{
		fprintf(stderr, "pthread_mutex_destroy error. [err=%s]",
			strerror(err));
	}

	LinkedQueue* linkedQueue =
	    container_of(linkedBlockingQueue->queue, LinkedQueue, iqueue);
	delete (LinkedQueue, linkedQueue);
}

void LinkedBlockingQueue_push(IQueue* iqueue, ICommand* command)
{
	LinkedBlockingQueue* linkedBlockingQueue =
	    container_of(iqueue, LinkedBlockingQueue, iqueue);

	int err = pthread_mutex_lock(&linkedBlockingQueue->mutex);
	if (err)
	{
		fprintf(stderr, "pthread_mutex_lock error. [err=%s]",
			strerror(err));
		return;
	}

	linkedBlockingQueue->queue->push(iqueue, command);

	err = pthread_mutex_unlock(&linkedBlockingQueue->mutex);
	if (err)
	{
		fprintf(stderr, "pthread_mutex_unlock error. [err=%s]",
			strerror(err));
	}

	err = pthread_cond_signal(&linkedBlockingQueue->cond);
	if (err)
	{
		fprintf(stderr, "pthread_cond_signal error. [err=%s]",
			strerror(err));
	}
}

ICommand* LinkedBlockingQueue_pop(IQueue* iqueue)
{
	LinkedBlockingQueue* linkedBlockingQueue =
	    container_of(iqueue, LinkedBlockingQueue, iqueue);

	int err = pthread_mutex_lock(&linkedBlockingQueue->mutex);
	if (err)
	{
		fprintf(stderr, "pthread_mutex_lock error. [err=%s]",
			strerror(err));
		return NULL;
	}

	while (linkedBlockingQueue->empty(iqueue))
	{
		err = pthread_cond_wait(&linkedBlockingQueue->cond,
					&linkedBlockingQueue->mutex);
		if (err)
		{
			fprintf(stderr, "pthread_cond_wait error. [err=%s]",
				strerror(err));
			return NULL;
		}
	}

	ICommand* command =
	    linkedBlockingQueue->queue->pop(linkedBlockingQueue->queue);
	err = pthread_mutex_unlock(&linkedBlockingQueue->mutex);
	if (err)
	{
		fprintf(stderr, "pthread_mutex_unlock error. [err=%s]",
			strerror(err));
		return NULL;
	}

	return command;
}

int LinkedBlockingQueue_empty(IQueue* iqueue)
{
	LinkedBlockingQueue* linkedBlockingQueue =
	    container_of(iqueue, LinkedBlockingQueue, iqueue);

	int isEmpty;
	int err = pthread_mutex_lock(&linkedBlockingQueue->mutex);
	if (err)
	{
		fprintf(stderr, "pthread_mutex_lock error. [err=%s]",
			strerror(err));
	}

	isEmpty = linkedBlockingQueue->queue->empty(linkedBlockingQueue->queue);

	err = pthread_mutex_unlock(&linkedBlockingQueue->mutex);
	if (err)
	{
		fprintf(stderr, "pthread_mutex_unlock error. [err=%s]",
			strerror(err));
	}

	return isEmpty;
}
