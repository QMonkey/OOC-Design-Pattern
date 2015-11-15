#include <stdio.h>

#include "base.h"
#include "ipermission.h"
#include "permission_type.h"
#include "permission_factory.h"

int main()
{
	PermissionFactory* permissionFactory = PermissionFactory_getInstance();
	IPermission* ipermission = NULL;

	ipermission = permissionFactory->createPermission(permissionFactory, Read);
	printf("%d\n", ipermission->match(ipermission, "read"));
	printf("%d\n", ipermission->match(ipermission, "delete"));

	ipermission = permissionFactory->createPermission(permissionFactory, Write);
	printf("%d\n", ipermission->match(ipermission, "write"));
	printf("%d\n", ipermission->match(ipermission, "delete"));

	ipermission = permissionFactory->createPermission(permissionFactory, ReadWrite);
	printf("%d\n", ipermission->match(ipermission, "read"));
	printf("%d\n", ipermission->match(ipermission, "write"));
	printf("%d\n", ipermission->match(ipermission, "delete"));

	return 0;
}
