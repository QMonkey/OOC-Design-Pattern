#include <stdio.h>

#include "base.h"
#include "ipermission.h"
#include "readwrite_permission.h"

static int ReadWritePermission_match(IPermission*, char*);

ReadWritePermission* ReadWritePermission_construct(void* addr, IPermission* permission1, IPermission* permission2)
{
	if (addr == NULL)
	{
		return NULL;
	}

	ReadWritePermission* readWritePermission = addr;
	readWritePermission->permissions[0] = permission1;
	readWritePermission->permissions[1] = permission2;

	readWritePermission->match = ReadWritePermission_match;

	return readWritePermission;
}

void ReadWritePermission_destruct(ReadWritePermission* readWritePermission)
{
}

int ReadWritePermission_match(IPermission* ipermission, char* permission)
{
	ReadWritePermission* readWritePermission = container_of(ipermission, ReadWritePermission, ipermission);
	IPermission** permissions = readWritePermission->permissions;
	return permissions[0]->match(permissions[0], permission) || permissions[1]->match(permissions[1], permission);
}
