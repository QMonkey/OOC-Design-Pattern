#ifndef IFILE_H
#define IFILE_H

typedef struct _IFile IFile;

struct _IFile
{
	void (*add)(IFile*, IFile*);
	void (*remove)(IFile*, IFile*);
	IFile* (*getChild)(IFile*, char*);
	char* (*getName)(IFile*);
	void (*setName)(IFile*, char*);
	char* (*getContent)(IFile*);
	void (*setContent)(IFile*, char*);
};

#endif
