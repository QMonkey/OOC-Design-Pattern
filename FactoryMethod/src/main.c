#include "base.h"
#include "iwidget.h"
#include "ifactory.h"
#include "linux_widget.h"
#include "linux_widget_factory.h"
#include "mac_widget.h"
#include "mac_widget_factory.h"
#include "windows_widget.h"
#include "windows_widget_factory.h"

int main()
{
	LinuxWidgetFactory* linuxWidgetFactory = new (LinuxWidgetFactory);
	IFactory* ifactory = &linuxWidgetFactory->ifactory;
	IWidget* iwidget = ifactory->createWidget(ifactory);
	iwidget->show(iwidget);
	delete (LinuxWidget, container_of(iwidget, LinuxWidget, iwidget));

	MacWidgetFactory* macWidgetFactory = new (MacWidgetFactory);
	ifactory = &macWidgetFactory->ifactory;
	iwidget = ifactory->createWidget(ifactory);
	iwidget->show(iwidget);
	delete (MacWidget, container_of(iwidget, MacWidget, iwidget));

	WindowsWidgetFactory* windowsWidgetFactory = new (WindowsWidgetFactory);
	ifactory = &windowsWidgetFactory->ifactory;
	iwidget = ifactory->createWidget(ifactory);
	iwidget->show(iwidget);
	delete (WindowsWidget, container_of(iwidget, WindowsWidget, iwidget));

	delete (LinuxWidgetFactory, linuxWidgetFactory);
	delete (MacWidgetFactory, macWidgetFactory);
	delete (WindowsWidgetFactory, windowsWidgetFactory);

	return 0;
}
