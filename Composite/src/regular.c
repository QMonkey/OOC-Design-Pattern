#include <stdio.h>

#include "base.h"
#include "ifile.h"
#include "abstract_file.h"
#include "regular.h"

static char* Regular_getContent(IFile*);
static void Regular_setContent(IFile*, char*);

Regular* Regular_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	Regular* regular = addr;
	regular->content = NULL;

	AbstractFile_construct(&regular->abstractFile);
	regular->getContent = Regular_getContent;
	regular->setContent = Regular_setContent;

	return regular;
}

void Regular_destruct(Regular* regular)
{
	AbstractFile_destruct(&regular->abstractFile);
}

char* Regular_getContent(IFile* ifile)
{
	Regular* regular = container_of(ifile, Regular, ifile);
	return regular->content;
}

void Regular_setContent(IFile* ifile, char* content)
{
	Regular* regular = container_of(ifile, Regular, ifile);
	regular->content = content;
}
