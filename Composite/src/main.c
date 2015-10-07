#include <stdio.h>

#include "base.h"
#include "ifile.h"
#include "directory.h"
#include "regular.h"

int main()
{
	Directory* directory = new (Directory);
	directory->setName(&directory->ifile, "directory");

	Regular* regular = new (Regular);
	regular->setName(&regular->ifile, "file1");
	regular->setContent(&regular->ifile, "this is file1.");
	directory->add(&directory->ifile, &regular->ifile);

	regular = new (Regular);
	regular->setName(&regular->ifile, "file2");
	regular->setContent(&regular->ifile, "this is file2.");
	directory->add(&directory->ifile, &regular->ifile);

	printf("directory name: %s\n", directory->getName(&directory->ifile));

	IFile* file = directory->getChild(&directory->ifile, "file1");
	regular = container_of(file, Regular, ifile);
	printf("file name: %s, file content: %s\n",
	       regular->getName(&regular->ifile),
	       regular->getContent(&regular->ifile));

	file = directory->getChild(&directory->ifile, "file2");
	regular = container_of(file, Regular, ifile);
	printf("file name: %s, file content: %s\n",
	       regular->getName(&regular->ifile),
	       regular->getContent(&regular->ifile));

	delete (Directory, directory);
	return 0;
}
