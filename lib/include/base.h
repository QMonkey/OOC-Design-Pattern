#ifndef BASE_H
#define BASE_H

#include <stdlib.h>
#include <stddef.h>

// clang-format off
#define container_of(ptr, type, member)					\
	({								\
		const typeof(((type *)0)->member ) *__mptr = (ptr);	\
		(type *)((char *)__mptr - offsetof(type,member));	\
	})

#define new(TYPE, args...) TYPE ## _construct(malloc(sizeof(TYPE)), ## args)
#define delete(TYPE, ptr)	do				\
				{				\
					TYPE ## _destruct(ptr);	\
					free(ptr);		\
				}				\
				while(0)
// clang-format on

#endif
