#ifndef ICLONE_H
#define ICLONE_H

typedef struct _IClone IClone;

struct _IClone
{
	IClone* (*clone)(IClone*);
};

#endif
