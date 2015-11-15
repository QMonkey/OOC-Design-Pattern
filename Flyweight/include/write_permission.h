#ifndef WRITE_PERMISSION_H
#define WRITE_PERMISSION_H

#include "ipermission.h"

typedef struct _WritePermission WritePermission;

struct _WritePermission
{
	union
	{
		IPermission;
		IPermission ipermission;
	};
};

extern WritePermission* WritePermission_construct(void*);
extern void WritePermission_destruct(WritePermission*);

#endif
