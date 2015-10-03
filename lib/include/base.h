#ifndef BASE_H
#define BASE_H

#include <stdlib.h>

#define offsetof(TYPE, MEMBER) ((size_t) &((TYPE *)0)->MEMBER)
#define container_of(ptr, type, member) ({                  \
	const typeof( ((type *)0)->member ) *__mptr = (ptr);    \
	(type *)( (char *)__mptr - offsetof(type,member) );})

#endif

#define new(TYPE, args...) construct ## TYPE(malloc(sizeof(TYPE)), ## args)
#define delete(TYPE, ptr)	do				\
				{				\
					destruct ## TYPE(ptr);	\
					free(ptr);		\
				}				\
				while(0)
