#include <stdio.h>

#include "base.h"
#include "iimage.h"
#include "real_image.h"
#include "proxy_image.h"

static void ProxyImage_display(IImage*);

extern ProxyImage* ProxyImage_construct(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	ProxyImage* proxyImage = addr;

	proxyImage->display = ProxyImage_display;

	return proxyImage;
}

extern void ProxyImage_destruct(ProxyImage* proxyImage)
{
	delete (RealImage, container_of(proxyImage->image, RealImage, iimage));
}

static void ProxyImage_display(IImage* iimage)
{
	ProxyImage* proxyImage = container_of(iimage, ProxyImage, iimage);
	proxyImage->image = &new (RealImage)->iimage;
	proxyImage->image->display(proxyImage->image);
}
