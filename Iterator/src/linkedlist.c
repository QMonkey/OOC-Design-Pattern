#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "base.h"
#include "ilist.h"
#include "iiterator.h"
#include "linkedlist.h"
#include "linkedlist_iterator.h"

static void LinkedList_push(IList*, int);
static int LinkedList_pop(IList*);
static size_t LinkedList_count(IList*);
static int LinkedList_empty(IList*);
static IIterator* LinkedList_iterator(IList*);

LinkedList* LinkedList_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	LinkedList* linkedList = addr;
	linkedList->head = NULL;

	linkedList->push = LinkedList_push;
	linkedList->pop = LinkedList_pop;
	linkedList->count = LinkedList_count;
	linkedList->empty = LinkedList_empty;
	linkedList->iterator = LinkedList_iterator;

	return linkedList;
}

void LinkedList_destruct(LinkedList* linkedList)
{
	ListNode* tmp = linkedList->head;
	while (linkedList->head != NULL)
	{
		linkedList->head = tmp->next;
		free(tmp);
		tmp = linkedList->head;
	}
}

void LinkedList_push(IList* ilist, int elem)
{
	LinkedList* linkedList = container_of(ilist, LinkedList, ilist);

	ListNode** node = &linkedList->head;
	while (*node != NULL)
	{
		node = &(*node)->next;
	}

	ListNode* tmpNode = (ListNode*)malloc(sizeof(ListNode));
	tmpNode->value = elem;
	tmpNode->next = NULL;

	*node = tmpNode;
}

int LinkedList_pop(IList* ilist)
{
	LinkedList* linkedList = container_of(ilist, LinkedList, ilist);
	assert(linkedList->head != NULL);

	ListNode* tmp = linkedList->head;
	linkedList->head = tmp->next;

	int value = tmp->value;
	free(tmp);

	return value;
}

size_t LinkedList_count(IList* ilist)
{
	LinkedList* linkedList = container_of(ilist, LinkedList, ilist);

	ListNode* tmp = linkedList->head;
	size_t count;
	for (count = 0; tmp != NULL; tmp = tmp->next)
	{
		++count;
	}

	return count;
}

int LinkedList_empty(IList* ilist)
{
	LinkedList* linkedList = container_of(ilist, LinkedList, ilist);
	return linkedList->head == NULL;
}

IIterator* LinkedList_iterator(IList* ilist)
{
	LinkedList* linkedList = container_of(ilist, LinkedList, ilist);
	return &new (LinkedListIterator, linkedList->head)->iiterator;
}
