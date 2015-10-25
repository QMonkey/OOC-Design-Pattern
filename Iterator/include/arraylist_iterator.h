#ifndef ARRAYLIST_ITERATOR_H
#define ARRAYLIST_ITERATOR_H

#include "iiterator.h"
#include "arraylist.h"

typedef struct _ArrayListIterator ArrayListIterator;

struct _ArrayListIterator
{
	size_t currentIndex;
	ArrayList* arrayList;

	union
	{
		IIterator;
		IIterator iiterator;
	};
};

extern ArrayListIterator* ArrayListIterator_construct(void*, ArrayList*);
extern void ArrayListIterator_destruct(ArrayListIterator*);

#endif
