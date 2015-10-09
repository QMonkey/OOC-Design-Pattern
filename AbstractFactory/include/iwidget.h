#ifndef IWIDGET_H
#define IWIDGET_H

typedef struct _IWidget IWidget;

struct _IWidget
{
	void (*show)(IWidget*);
};

#endif
