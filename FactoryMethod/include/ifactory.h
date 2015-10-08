#ifndef IFACTORY_H
#define IFACTORY_H

#include "iwidget.h"

typedef struct _IFactory IFactory;

struct _IFactory
{
	IWidget* (*createWidget)(IFactory*);
};

#endif
