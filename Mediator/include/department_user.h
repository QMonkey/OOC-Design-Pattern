#ifndef DEPARTMENT_USER_H
#define DEPARTMENT_USER_H

typedef struct _DepartmentUser DepartmentUser;

struct _DepartmentUser
{
	int (*getDepartmentId)(DepartmentUser*);
	int (*getUserId)(DepartmentUser*);

	int departmentId;
	int userId;
};

extern DepartmentUser* DepartmentUser_construct(void*, int, int);
extern void DepartmentUser_destruct(DepartmentUser*);

#endif
