#include <stdio.h>

#include "base.h"
#include "icommand.h"
#include "iqueue.h"
#include "linkedlist.h"
#include "linkedqueue.h"

static void LinkedQueue_push(IQueue*, ICommand*);
static ICommand* LinkedQueue_pop(IQueue*);
static int LinkedQueue_empty(IQueue*);

LinkedQueue* LinkedQueue_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	LinkedQueue* linkedQueue = addr;
	linkedQueue->list = &new (LinkedList)->ilist;

	linkedQueue->push = LinkedQueue_push;
	linkedQueue->pop = LinkedQueue_pop;
	linkedQueue->empty = LinkedQueue_empty;

	return linkedQueue;
}

void LinkedQueue_destruct(LinkedQueue* linkedQueue)
{
	LinkedList* linkedList =
	    container_of(linkedQueue->list, LinkedList, ilist);
	delete (LinkedList, linkedList);
}

void LinkedQueue_push(IQueue* iqueue, ICommand* command)
{
	LinkedQueue* linkedQueue = container_of(iqueue, LinkedQueue, iqueue);
	linkedQueue->list->push(linkedQueue->list, command);
}

ICommand* LinkedQueue_pop(IQueue* iqueue)
{
	LinkedQueue* linkedQueue = container_of(iqueue, LinkedQueue, iqueue);
	return linkedQueue->list->pop(linkedQueue->list);
}

int LinkedQueue_empty(IQueue* iqueue)
{
	LinkedQueue* linkedQueue = container_of(iqueue, LinkedQueue, iqueue);
	return linkedQueue->list->empty(linkedQueue->list);
}
