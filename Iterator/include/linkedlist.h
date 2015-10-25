#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "ilist.h"

typedef struct _LinkedList LinkedList;
typedef struct _ListNode ListNode;

struct _ListNode
{
	int value;
	ListNode* next;
};

struct _LinkedList
{
	ListNode* head;

	union
	{
		IList;
		IList ilist;
	};
};

extern LinkedList* LinkedList_construct(void*);
extern void LinkedList_destruct(LinkedList*);

#endif
