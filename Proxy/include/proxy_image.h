#ifndef PROXY_IMAGE_H
#define PROXY_IMAGE_H

#include "iimage.h"

typedef struct _ProxyImage ProxyImage;

struct _ProxyImage
{
	IImage* image;
	union
	{
		IImage;
		IImage iimage;
	};
};

extern ProxyImage* ProxyImage_construct(void*);
extern void ProxyImage_destruct(ProxyImage*);

#endif
