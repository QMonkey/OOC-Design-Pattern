#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <stddef.h>

#include "ilist.h"

typedef struct _ArrayList ArrayList;

struct _ArrayList
{
	int* data;
	size_t capacity;
	size_t size;

	int (*get)(ArrayList*, size_t);
	union
	{
		IList;
		IList ilist;
	};
};

extern ArrayList* ArrayList_construct(void*, size_t);
extern void ArrayList_destruct(ArrayList*);

#endif
