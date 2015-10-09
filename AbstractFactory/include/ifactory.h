#ifndef IFACTORY_H
#define IFACTORY_H

#include "iwidget.h"
#include "ibutton.h"

typedef struct _IFactory IFactory;

struct _IFactory
{
	IWidget* (*createWidget)(IFactory*);
	IButton* (*createButton)(IFactory*);
};

#endif
