#ifndef TARGET_H
#define TARGET_H

#include "itarget.h"

typedef struct _Target Target;

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
