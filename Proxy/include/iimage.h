#ifndef IIMAGE_H
#define IIMAGE_H

typedef struct _IImage IImage;

struct _IImage
{
	void (*display)(IImage*);
};

#endif
