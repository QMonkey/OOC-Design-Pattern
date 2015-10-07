#include <stdio.h>

#include "base.h"
#include "ifile.h"
#include "abstract_file.h"
#include "regular.h"

static char* Regular_getContent(IFile*);
static void Regular_setContent(IFile*, char*);

Regular* constructRegular(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	Regular* regular = addr;
	regular->content = NULL;

	constructAbstractFile(&regular->abstractFile);
	regular->getContent = Regular_getContent;
	regular->setContent = Regular_setContent;

	return regular;
}

void destructRegular(Regular* regular)
{
	destructAbstractFile(&regular->abstractFile);
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
