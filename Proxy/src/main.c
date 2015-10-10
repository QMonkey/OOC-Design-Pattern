#include "base.h"
#include "iimage.h"
#include "proxy_image.h"

int main()
{
	ProxyImage* proxyImage = new (ProxyImage);
	IImage* iimage = &proxyImage->iimage;

	iimage->display(iimage);

	delete (ProxyImage, proxyImage);
	return 0;
}
