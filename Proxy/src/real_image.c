#include <stdio.h>

#include "iimage.h"
#include "real_image.h"

static void RealImage_load(RealImage*);
static void RealImage_display(IImage*);

RealImage* constructRealImage(void* addr)
{
	if (addr == NULL)
	{
		return NULL;
	}

	RealImage* realImage = addr;

	realImage->load = RealImage_load;
	realImage->display = RealImage_display;

	realImage->load(realImage);

	return realImage;
}

void destructRealImage(RealImage* realImage)
{
}

void RealImage_load(RealImage* realImage)
{
	printf("Load real image!\n");
}

void RealImage_display(IImage* iimage)
{
	printf("Display image!\n");
}
