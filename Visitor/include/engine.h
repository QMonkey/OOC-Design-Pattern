#ifndef ENGINE_H
#define ENGINE_H

#include "icar_element.h"

typedef struct _Engine Engine;

struct _Engine
{
	union
	{
		ICarElement;
		ICarElement icarElement;
	};
};

extern Engine* Engine_construct(void*);
extern void Engine_destruct(Engine*);

#endif
