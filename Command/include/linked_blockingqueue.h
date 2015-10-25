#ifndef LINKED_BLOCKINGQUEUE_H
#define LINKED_BLOCKINGQUEUE_H

#include <pthread.h>

#include "iblockingqueue.h"

typedef struct _LinkedBlockingQueue LinkedBlockingQueue;

struct _LinkedBlockingQueue
{
	pthread_mutex_t mutex;
	pthread_cond_t cond;
	IQueue* queue;

	union
	{
		IBlockingQueue;
		IBlockingQueue iblockingQueue;
	};
};

extern LinkedBlockingQueue* LinkedBlockingQueue_construct(void*);
extern void LinkedBlockingQueue_destruct(LinkedBlockingQueue*);

#endif
