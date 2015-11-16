#include <stdio.h>

#include "base.h"
#include "icar_element.h"
#include "icar_element_visitor.h"
#include "engine.h"

static char* Engine_getName(ICarElement*);
static void Engine_accept(ICarElement*, ICarElementVisitor*);

Engine* Engine_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	Engine* engine = addr;

	engine->getName = Engine_getName;
	engine->accept = Engine_accept;

	return engine;
}

void Engine_destruct(Engine* engine)
{
}

char* Engine_getName(ICarElement* icarElement)
{
	return "Engine";
}

void Engine_accept(ICarElement* icarElement, ICarElementVisitor* carElementVisitor)
{
	Engine* engine = container_of(icarElement, Engine, icarElement);
	carElementVisitor->visitEngine(carElementVisitor, engine);
}
