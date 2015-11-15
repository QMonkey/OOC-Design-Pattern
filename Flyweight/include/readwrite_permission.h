#ifndef READWRITE_PERMISSION_H
#define READWRITE_PERMISSION_H

#include "ipermission.h"

typedef struct _ReadWritePermission ReadWritePermission;

struct _ReadWritePermission
{
	IPermission* permissions[2];

	union
	{
		IPermission;
		IPermission ipermission;
	};
};

extern ReadWritePermission* ReadWritePermission_construct(void*, IPermission*, IPermission*);
extern void ReadWritePermission_destruct(ReadWritePermission*);

#endif
