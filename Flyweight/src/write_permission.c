#include <stdio.h>
#include <string.h>

#include "ipermission.h"
#include "write_permission.h"

static int WritePermission_match(IPermission*, char*);

WritePermission* WritePermission_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	WritePermission* writePermission = addr;

	writePermission->match = WritePermission_match;

	return writePermission;
}

void WritePermission_destruct(WritePermission* writePermission)
{
}

int WritePermission_match(IPermission* ipermission, char* permission)
{
	return strcmp(permission, "write") == 0;
}
