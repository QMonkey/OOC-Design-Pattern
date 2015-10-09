#include "base.h"
#include "iwidget.h"
#include "ibutton.h"
#include "ifactory.h"
#include "linux_widget.h"
#include "linux_button.h"
#include "linux_factory.h"
#include "mac_widget.h"
#include "mac_button.h"
#include "mac_factory.h"
#include "windows_widget.h"
#include "windows_button.h"
#include "windows_factory.h"

int main()
{
	LinuxFactory* linuxFactory = new (LinuxFactory);
	IFactory* ifactory = &linuxFactory->ifactory;
	IWidget* iwidget = ifactory->createWidget(ifactory);
	iwidget->show(iwidget);
	IButton* ibutton = ifactory->createButton(ifactory);
	ibutton->click(ibutton);
	delete (LinuxWidget, container_of(iwidget, LinuxWidget, iwidget));
	delete (LinuxButton, container_of(ibutton, LinuxButton, ibutton));

	MacFactory* macFactory = new (MacFactory);
	ifactory = &macFactory->ifactory;
	iwidget = ifactory->createWidget(ifactory);
	iwidget->show(iwidget);
	ibutton = ifactory->createButton(ifactory);
	ibutton->click(ibutton);
	delete (MacWidget, container_of(iwidget, MacWidget, iwidget));
	delete (MacButton, container_of(ibutton, MacButton, ibutton));

	WindowsFactory* windowsFactory = new (WindowsFactory);
	ifactory = &windowsFactory->ifactory;
	iwidget = ifactory->createWidget(ifactory);
	iwidget->show(iwidget);
	ibutton = ifactory->createButton(ifactory);
	ibutton->click(ibutton);
	delete (WindowsWidget, container_of(iwidget, WindowsWidget, iwidget));
	delete (WindowsButton, container_of(ibutton, WindowsButton, ibutton));

	delete (LinuxFactory, linuxFactory);
	delete (MacFactory, macFactory);
	delete (WindowsFactory, windowsFactory);

	return 0;
}
