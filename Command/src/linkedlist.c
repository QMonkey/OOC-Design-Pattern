#include <stdio.h>
#include "base.h"
#include "icommand.h"
#include "ilist.h"
#include "linkedlist.h"

static void LinkedList_push(IList*, ICommand*);
static ICommand* LinkedList_pop(IList*);
static size_t LinkedList_count(IList*);
static int LinkedList_empty(IList*);

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

	return linkedList;
}

void LinkedList_destruct(LinkedList* linkedList)
{
	LinkedListNode* tmp = linkedList->head;
	while (linkedList->head != NULL)
	{
		linkedList->head = tmp->next;
		free(tmp);
		tmp = linkedList->head;
	}
}

void LinkedList_push(IList* ilist, ICommand* command)
{
	LinkedList* linkedList = container_of(ilist, LinkedList, ilist);

	LinkedListNode* node = malloc(sizeof(LinkedListNode));
	if (node == NULL)
	{
		return;
	}

	node->command = command;
	node->next = NULL;

	LinkedListNode** nodePtr = &linkedList->head;
	while (*nodePtr != NULL)
	{
		nodePtr = &(*nodePtr)->next;
	}

	*nodePtr = node;
}

ICommand* LinkedList_pop(IList* ilist)
{
	LinkedList* linkedList = container_of(ilist, LinkedList, ilist);

	if (linkedList->head == NULL)
	{
		return NULL;
	}

	LinkedListNode* tmp = linkedList->head;
	linkedList->head = tmp->next;
	tmp->next = NULL;

	return tmp->command;
}

size_t LinkedList_count(IList* ilist)
{
	LinkedList* linkedList = container_of(ilist, LinkedList, ilist);

	size_t count = 0;
	LinkedListNode* tmp = linkedList->head;
	while (tmp != NULL)
	{
		++count;
		tmp = tmp->next;
	}

	return count;
}

int LinkedList_empty(IList* ilist)
{
	LinkedList* linkedList = container_of(ilist, LinkedList, ilist);
	return linkedList->head == NULL;
}
