#ifndef IBLOCKINGQUEUE_H
#define IBLOCKINGQUEUE_H

#include "iqueue.h"

typedef struct _IBlockingQueue IBlockingQueue;

struct _IBlockingQueue
{
	union
	{
		IQueue;
		IQueue iqueue;
	};
};

#endif
