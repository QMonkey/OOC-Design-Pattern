#ifndef TARGET_H
#define TARGET_H

typedef struct _ITarget ITarget;
typedef struct _Target Target;

struct _ITarget
{
	long (*powerOf2)(ITarget*, int);
};

struct _Target
{
	union
	{
		ITarget;
		ITarget itarget;
	};
};

extern Target* constructTarget(void*);
extern void destructTarget(Target*);

#endif
