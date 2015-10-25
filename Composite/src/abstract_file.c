#include <stdio.h>
#include <stdlib.h>

#include "base.h"
#include "ifile.h"
#include "abstract_file.h"

static void AbstractFile_add(IFile*, IFile*);
static void AbstractFile_remove(IFile*, IFile*);
static IFile* AbstractFile_getChild(IFile*, char*);
static char* AbstractFile_getName(IFile*);
static void AbstractFile_setName(IFile*, char*);
static char* AbstractFile_getContent(IFile*);
static void AbstractFile_setContent(IFile*, char*);
static void AbstractFile_unsupportOperation(IFile*);

void AbstractFile_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	AbstractFile* abstractFile = addr;
	abstractFile->name = NULL;

	abstractFile->add = AbstractFile_add;
	abstractFile->remove = AbstractFile_remove;
	abstractFile->getChild = AbstractFile_getChild;
	abstractFile->getName = AbstractFile_getName;
	abstractFile->setName = AbstractFile_setName;
	abstractFile->getContent = AbstractFile_getContent;
	abstractFile->setContent = AbstractFile_setContent;
}

void AbstractFile_destruct(AbstractFile* abstractFile)
{
}

void AbstractFile_add(IFile* ifile, IFile* file)
{
	AbstractFile_unsupportOperation(ifile);
}

void AbstractFile_remove(IFile* ifile, IFile* file)
{
	AbstractFile_unsupportOperation(ifile);
}

IFile* AbstractFile_getChild(IFile* ifile, char* fileName)
{
	AbstractFile_unsupportOperation(ifile);
	return NULL;
}

char* AbstractFile_getName(IFile* ifile)
{
	AbstractFile* abstractFile = container_of(ifile, AbstractFile, ifile);
	return abstractFile->name;
}

void AbstractFile_setName(IFile* ifile, char* filename)
{
	AbstractFile* abstractFile = container_of(ifile, AbstractFile, ifile);
	abstractFile->name = filename;
}

char* AbstractFile_getContent(IFile* ifile)
{
	AbstractFile_unsupportOperation(ifile);
	return NULL;
}

void AbstractFile_setContent(IFile* ifile, char* content)
{
	AbstractFile_unsupportOperation(ifile);
}

void AbstractFile_unsupportOperation(IFile* ifile)
{
	fprintf(stderr, "Unsupported operation.\n");
	abort();
}
