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

extern ProxyImage* constructProxyImage(void*);
extern void destructProxyImage(ProxyImage*);

#endif
