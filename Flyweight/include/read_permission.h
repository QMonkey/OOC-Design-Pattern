#ifndef READ_PERMISSION_H
#define READ_PERMISSION_H

#include "ipermission.h"

typedef struct _ReadPermission ReadPermission;

struct _ReadPermission
{
	union
	{
		IPermission;
		IPermission ipermission;
	};
};

extern ReadPermission* ReadPermission_construct(void*);
extern void ReadPermission_destruct(ReadPermission*);

#endif
