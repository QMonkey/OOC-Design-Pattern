#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "base.h"
#include "ipermission.h"
#include "permission_type.h"
#include "read_permission.h"
#include "write_permission.h"
#include "readwrite_permission.h"
#include "permission_factory.h"

static pthread_once_t once = PTHREAD_ONCE_INIT;
static PermissionFactory* permissionFactory = NULL;

static PermissionFactory* PermissionFactory_construct(void* addr);
static IPermission* PermissionFactory_createPermission(PermissionFactory*, PermissionType);

PermissionFactory* PermissionFactory_getInstance()
{
	void init()
	{
		permissionFactory = new (PermissionFactory);
	}

	int err = pthread_once(&once, init);
	if (err)
	{
		perror(strerror(err));
		abort();
	}

	return permissionFactory;
}

PermissionFactory* PermissionFactory_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	PermissionFactory* permissionFactory = addr;
	permissionFactory->readPermission = &new (ReadPermission)->ipermission;
	permissionFactory->writePermission = &new (WritePermission)->ipermission;
	permissionFactory->readWritePermission = &new (ReadWritePermission, permissionFactory->readPermission, permissionFactory->writePermission)->ipermission;

	permissionFactory->createPermission = PermissionFactory_createPermission;

	return permissionFactory;
}

IPermission* PermissionFactory_createPermission(PermissionFactory* permissionFactory, PermissionType permissionType)
{
	IPermission* permission = NULL;
	switch (permissionType)
	{
	case Read:
		permission = permissionFactory->readPermission;
		break;

	case Write:
		permission = permissionFactory->writePermission;
		break;

	case ReadWrite:
		permission = permissionFactory->readWritePermission;
		break;

	default:
		break;
	}

	return permission;
}
