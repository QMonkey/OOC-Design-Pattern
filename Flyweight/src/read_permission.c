#include <stdio.h>
#include <string.h>

#include "ipermission.h"
#include "read_permission.h"

static int ReadPermission_match(IPermission*, char*);

ReadPermission* ReadPermission_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	ReadPermission* readPermission = addr;

	readPermission->match = ReadPermission_match;

	return readPermission;
}

void ReadPermission_destruct(ReadPermission* readPermission)
{
}

int ReadPermission_match(IPermission* ipermission, char* permission)
{
	return strcmp(permission, "read") == 0;
}
