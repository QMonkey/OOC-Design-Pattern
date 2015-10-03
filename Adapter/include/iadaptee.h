#ifndef IADAPTEE_H
#define IADAPTEE_H

typedef struct _IAdaptee IAdaptee;

struct _IAdaptee
{
	long (*power)(IAdaptee*, int, int);
};

#endif
