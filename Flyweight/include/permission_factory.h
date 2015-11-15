#ifndef PERMISSION_FACTORY_H
#define PERMISSION_FACTORY_H

#include "ipermission.h"
#include "permission_type.h"

typedef struct _PermissionFactory PermissionFactory;

struct _PermissionFactory
{
	IPermission* readPermission;
	IPermission* writePermission;
	IPermission* readWritePermission;

	IPermission* (*createPermission)(PermissionFactory*, PermissionType);
};

extern PermissionFactory* PermissionFactory_getInstance();

#endif
