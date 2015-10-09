#ifndef IBUTTON_H
#define IBUTTON_H

typedef struct _IButton IButton;

struct _IButton
{
	void (*click)(IButton*);
};

#endif
