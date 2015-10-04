#ifndef LINKEDLIST_ITERATOR_H
#define LINKEDLIST_ITERATOR_H

#include "iiterator.h"
#include "linkedlist.h"

typedef struct _LinkedListIterator LinkedListIterator;

struct _LinkedListIterator
{
	ListNode *currentNode;

	union
	{
		IIterator;
		IIterator iiterator;
	};
};

extern LinkedListIterator* constructLinkedListIterator(void*, ListNode*);
extern void destructLinkedListIterator(LinkedListIterator*);

#endif
