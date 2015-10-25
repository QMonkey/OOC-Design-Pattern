#include <stdio.h>

#include "base.h"
#include "iiterator.h"
#include "arraylist_iterator.h"
#include "arraylist.h"

static int ArrayListIterator_hasNext(IIterator*);
static int ArrayListIterator_next(IIterator*);

ArrayListIterator* ArrayListIterator_construct(void* addr, ArrayList* arrayList)
{
	if (addr == NULL)
	{
		return NULL;
	}

	ArrayListIterator* arrayListIterator = addr;
	arrayListIterator->arrayList = arrayList;
	arrayListIterator->currentIndex = 0;

	arrayListIterator->hasNext = ArrayListIterator_hasNext;
	arrayListIterator->next = ArrayListIterator_next;

	return arrayListIterator;
}

void ArrayListIterator_destruct(ArrayListIterator* arrayListIterator)
{
}

int ArrayListIterator_hasNext(IIterator* iiterator)
{
	ArrayListIterator* arrayListIterator =
	    container_of(iiterator, ArrayListIterator, iiterator);
	ArrayList* arrayList = arrayListIterator->arrayList;
	return arrayListIterator->currentIndex <
	       arrayList->count(&arrayList->ilist);
}

int ArrayListIterator_next(IIterator* iiterator)
{
	ArrayListIterator* arrayListIterator =
	    container_of(iiterator, ArrayListIterator, iiterator);
	ArrayList* arrayList = arrayListIterator->arrayList;
	return arrayList->get(arrayList, arrayListIterator->currentIndex++);
}
