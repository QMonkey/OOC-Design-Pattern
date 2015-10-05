#ifndef IQUEUE_H
#define IQUEUE_H

#include "icommand.h"

typedef struct _IQueue IQueue;

struct _IQueue
{
	void (*push)(IQueue*, ICommand*);
	ICommand* (*pop)(IQueue*);
	int (*empty)(IQueue*);
};

#endif
