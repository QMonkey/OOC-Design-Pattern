#ifndef ICOMMAND_H
#define ICOMMAND_H

typedef struct _ICommand ICommand;

struct _ICommand
{
	void (*execute)(ICommand*);
};

#endif
