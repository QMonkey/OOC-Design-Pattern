#ifndef IWINDOW_H
#define IWINDOW_H

typedef struct _IWindow IWindow;

struct _IWindow
{
	void (*draw)(IWindow*);
};

#endif
