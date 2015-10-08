#ifndef ILIST_H
#define ILIST_H

#include <stddef.h>

#include "iiterator.h"

typedef struct _IList IList;

struct _IList
{
	void (*push)(IList*, int);
	int (*pop)(IList*);
	size_t (*count)(IList*);
	int (*empty)(IList*);
	IIterator* (*iterator)(IList*);
};

#endif
