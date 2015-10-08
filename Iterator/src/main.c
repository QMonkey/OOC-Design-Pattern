#include <stdio.h>

#include "base.h"
#include "ilist.h"
#include "iiterator.h"
#include "arraylist.h"
#include "arraylist_iterator.h"
#include "linkedlist.h"
#include "linkedlist_iterator.h"

int main()
{
	ArrayList* arrayList = new (ArrayList, 3);
	LinkedList* linkedList = new (LinkedList);

	int i;
	for (i = 0; i < 10; ++i)
	{
		arrayList->push(&arrayList->ilist, i);
		linkedList->push(&linkedList->ilist, i * (-1));
	}

	IIterator* iterator = arrayList->iterator(&arrayList->ilist);
	while (iterator->hasNext(iterator))
	{
		printf("%d ", iterator->next(iterator));
	}
	printf("\n");

	ArrayListIterator* arrayListIterator =
	    container_of(iterator, ArrayListIterator, iiterator);
	delete (ArrayListIterator, arrayListIterator);

	iterator = linkedList->iterator(&linkedList->ilist);
	while (iterator->hasNext(iterator))
	{
		printf("%d ", iterator->next(iterator));
	}
	printf("\n");

	LinkedListIterator* linkedListIterator =
	    container_of(iterator, LinkedListIterator, iiterator);
	delete (LinkedListIterator, linkedListIterator);

	delete (ArrayList, arrayList);
	delete (LinkedList, linkedList);

	return 0;
}
