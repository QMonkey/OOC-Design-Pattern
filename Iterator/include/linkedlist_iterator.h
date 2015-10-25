#ifndef LINKEDLIST_ITERATOR_H
#define LINKEDLIST_ITERATOR_H

#include "iiterator.h"
#include "linkedlist.h"

typedef struct _LinkedListIterator LinkedListIterator;

struct _LinkedListIterator
{
	ListNode* currentNode;

	union
	{
		IIterator;
		IIterator iiterator;
	};
};

extern LinkedListIterator* LinkedListIterator_construct(void*, ListNode*);
extern void LinkedListIterator_destruct(LinkedListIterator*);

#endif
