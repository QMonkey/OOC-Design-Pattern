#ifndef ILIST_H
#define ILIST_H

#include "icommand.h"

typedef struct _IList IList;

struct _IList
{
	void (*push)(IList*, ICommand*);
	ICommand* (*pop)(IList*);
	size_t (*count)(IList*);
	int (*empty)(IList*);
};

#endif
