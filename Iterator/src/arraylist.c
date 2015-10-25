#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "base.h"
#include "ilist.h"
#include "iiterator.h"
#include "arraylist.h"
#include "arraylist_iterator.h"

static void ArrayList_push(IList*, int);
static int ArrayList_pop(IList*);
static size_t ArrayList_count(IList*);
static int ArrayList_empty(IList*);
static IIterator* ArrayList_iterator(IList*);
static int ArrayList_get(ArrayList*, size_t);
static void ArrayList_resize(ArrayList*, size_t);

ArrayList* ArrayList_construct(void* addr, size_t size)
{
	if (addr == NULL)
	{
		return NULL;
	}

	if (size <= 0)
	{
		size = 1;
	}

	ArrayList* arrayList = addr;
	arrayList->capacity = 0;
	arrayList->size = size;

	arrayList->data = (int*)malloc(sizeof(int) * size);

	arrayList->get = ArrayList_get;
	arrayList->push = ArrayList_push;
	arrayList->pop = ArrayList_pop;
	arrayList->count = ArrayList_count;
	arrayList->empty = ArrayList_empty;
	arrayList->iterator = ArrayList_iterator;

	return arrayList;
}

void ArrayList_destruct(ArrayList* arrayList)
{
	free(arrayList->data);
}

void ArrayList_push(IList* ilist, int elem)
{
	ArrayList* arrayList = container_of(ilist, ArrayList, ilist);
	if (arrayList->capacity == arrayList->size)
	{
		ArrayList_resize(arrayList, arrayList->size << 1);
	}
	arrayList->data[arrayList->capacity++] = elem;
}

int ArrayList_pop(IList* ilist)
{
	ArrayList* arrayList = container_of(ilist, ArrayList, ilist);
	return arrayList->data[--arrayList->capacity];
}

size_t ArrayList_count(IList* ilist)
{
	ArrayList* arrayList = container_of(ilist, ArrayList, ilist);
	return arrayList->capacity;
}

int ArrayList_empty(IList* ilist)
{
	ArrayList* arrayList = container_of(ilist, ArrayList, ilist);
	return arrayList->capacity == 0;
}

IIterator* ArrayList_iterator(IList* ilist)
{
	ArrayList* arrayList = container_of(ilist, ArrayList, ilist);
	return &new (ArrayListIterator, arrayList)->iiterator;
}

int ArrayList_get(ArrayList* arrayList, size_t index)
{
	return arrayList->data[index];
}

void ArrayList_resize(ArrayList* arrayList, size_t size)
{
	if (size <= arrayList->size)
	{
		return;
	}

	int* data = (int*)malloc(sizeof(int) * size);

	memcpy(data, arrayList->data, arrayList->size * sizeof(int));
	free(arrayList->data);

	arrayList->data = data;
	arrayList->size = size;
}
