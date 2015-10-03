#ifndef ITARGET_H
#define ITARGET_H

typedef struct _ITarget ITarget;

struct _ITarget
{
	long (*powerOf2)(ITarget*, int);
};

#endif
