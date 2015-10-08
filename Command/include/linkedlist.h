#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "ilist.h"
#include "icommand.h"

typedef struct _LinkedList LinkedList;
typedef struct _LinkedListNode LinkedListNode;

struct _LinkedList
{
	LinkedListNode* head;

	union
	{
		IList;
		IList ilist;
	};
};

struct _LinkedListNode
{
	ICommand* command;
	LinkedListNode* next;
};

extern LinkedList* constructLinkedList(void*);
extern void destructLinkedList(LinkedList*);

#endif
