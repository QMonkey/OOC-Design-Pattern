#ifndef ABSTRACT_FILE_H
#define ABSTRACT_FILE_H

#include "ifile.h"

typedef struct _AbstractFile AbstractFile;

struct _AbstractFile
{
	char* name;

	union
	{
		IFile;
		IFile ifile;
	};
};

extern void AbstractFile_construct(void*);
extern void AbstractFile_destruct(AbstractFile*);

#endif
