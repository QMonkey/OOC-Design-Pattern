#ifndef IITERATOR_H
#define IITERATOR_H

typedef struct _IIterator IIterator;

struct _IIterator
{
	int (*hasNext)(IIterator*);
	int (*next)(IIterator*);
};

#endif
