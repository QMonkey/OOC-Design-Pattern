#ifndef REGULAR_H
#define REGULAR_H

#include "ifile.h"
#include "abstract_file.h"

typedef struct _Regular Regular;

struct _Regular
{
	char* content;

	union
	{
		AbstractFile;
		AbstractFile abstractFile;
	};
};

extern Regular* Regular_construct(void*);
extern void Regular_destruct(Regular*);

#endif
