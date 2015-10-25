#ifndef REAL_IMAGE_H
#define REAL_IMAGE_H

#include "iimage.h"

typedef struct _RealImage RealImage;

struct _RealImage
{
	void (*load)(RealImage*);
	union
	{
		IImage;
		IImage iimage;
	};
};

extern RealImage* RealImage_construct(void*);
extern void RealImage_destruct(RealImage*);

#endif
