#include <stdio.h>

#include "base.h"
#include "iiterator.h"
#include "linkedlist_iterator.h"
#include "linkedlist.h"

static int LinkedListIterator_hasNext(IIterator*);
static int LinkedListIterator_next(IIterator*);

LinkedListIterator* LinkedListIterator_construct(void* addr, ListNode* node)
{
	if (addr == NULL)
	{
		return NULL;
	}

	LinkedListIterator* linkedListIterator = addr;
	linkedListIterator->currentNode = node;

	linkedListIterator->hasNext = LinkedListIterator_hasNext;
	linkedListIterator->next = LinkedListIterator_next;

	return linkedListIterator;
}

void LinkedListIterator_destruct(LinkedListIterator* linkedListIterator)
{
}

int LinkedListIterator_hasNext(IIterator* iiterator)
{
	LinkedListIterator* linkedListIterator =
	    container_of(iiterator, LinkedListIterator, iiterator);
	return linkedListIterator->currentNode != NULL;
}

int LinkedListIterator_next(IIterator* iiterator)
{
	LinkedListIterator* linkedListIterator =
	    container_of(iiterator, LinkedListIterator, iiterator);
	int value = linkedListIterator->currentNode->value;
	linkedListIterator->currentNode = linkedListIterator->currentNode->next;
	return value;
}
