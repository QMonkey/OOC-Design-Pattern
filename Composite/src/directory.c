#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "base.h"
#include "ifile.h"
#include "abstract_file.h"
#include "directory.h"

static void Directory_add(IFile*, IFile*);
static void Directory_remove(IFile*, IFile*);
static IFile* Directory_getChild(IFile*, char*);

Directory* Directory_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	Directory* directory = addr;
	directory->files = malloc(sizeof(IFile*));
	if (directory->files == NULL)
	{
		return NULL;
	}

	directory->count = 0;
	directory->size = 1;

	AbstractFile_construct(&directory->abstractFile);
	directory->add = Directory_add;
	directory->remove = Directory_remove;
	directory->getChild = Directory_getChild;

	return directory;
}

void Directory_destruct(Directory* directory)
{
	AbstractFile_destruct(&directory->abstractFile);
	// TODO delete files
}

void Directory_add(IFile* ifile, IFile* file)
{
	// TODO filename unique
	Directory* directory = container_of(ifile, Directory, ifile);
	if (directory->count == directory->size)
	{
		size_t size = directory->size << 1;
		IFile** tmpFiles = malloc(sizeof(IFile*) * size);
		memcpy(tmpFiles, directory->files,
		       sizeof(IFile*) * directory->count);
		free(directory->files);
		directory->files = tmpFiles;
		directory->size = size;
	}

	directory->files[directory->count++] = file;
}

void Directory_remove(IFile* ifile, IFile* file)
{
	Directory* directory = container_of(ifile, Directory, ifile);
	if (directory->files == NULL || directory->count == 0)
	{
		return;
	}

	AbstractFile* removeFile = container_of(file, AbstractFile, ifile);

	int i;
	for (i = 0; i < directory->count; ++i)
	{
		AbstractFile* abstractFile =
		    container_of(directory->files[i], AbstractFile, ifile);
		if (!strcmp(abstractFile->name, removeFile->name))
		{
			break;
		}
	}

	if (i == directory->count)
	{
		return;
	}

	--directory->count;
	memmove(directory->files + i, directory->files + i + 1,
		(directory->count - i) * sizeof(IFile*));
}

IFile* Directory_getChild(IFile* ifile, char* filename)
{
	Directory* directory = container_of(ifile, Directory, ifile);
	if (directory->files == NULL || directory->count == 0)
	{
		return NULL;
	}

	int i;
	for (i = 0; i < directory->count; ++i)
	{
		IFile* file = directory->files[i];
		AbstractFile* abstractFile =
		    container_of(file, AbstractFile, ifile);
		if (!strcmp(abstractFile->name, filename))
		{
			return file;
		}
	}

	return NULL;
}
