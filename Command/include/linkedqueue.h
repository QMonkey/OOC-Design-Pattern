#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H

#include "ilist.h"
#include "iqueue.h"

typedef struct _LinkedQueue LinkedQueue;

struct _LinkedQueue
{
	IList* list;

	union
	{
		IQueue;
		IQueue iqueue;
	};
};

extern LinkedQueue* LinkedQueue_construct(void*);
extern void LinkedQueue_destruct(LinkedQueue*);

#endif
