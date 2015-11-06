#ifndef IMANAGER_H
#define IMANAGER_H

typedef struct _IManager IManager;

struct _IManager
{
	int (*handleAskForLeaveRequest)(IManager*, char*, int);
	int (*handleRaisesRequest)(IManager*, char*, int);
};

#endif
