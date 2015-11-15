#ifndef IPERMISSION_H
#define IPERMISSION_H

typedef struct _IPermission IPermission;

struct _IPermission
{
	int (*match)(IPermission*, char*);
};

#endif
