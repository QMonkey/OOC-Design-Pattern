#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <stddef.h>

#include "ifile.h"
#include "abstract_file.h"

typedef struct _Directory Directory;

struct _Directory
{
	IFile** files;
	size_t count;
	size_t size;

	union
	{
		AbstractFile;
		AbstractFile abstractFile;
	};
};

extern Directory* Directory_construct(void*);
extern void Directory_destruct(Directory*);

#endif
