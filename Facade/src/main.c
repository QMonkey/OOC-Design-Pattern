#include "base.h"
#include "computer_facade.h"

int main()
{
	ComputerFacade* computerFacade = new (ComputerFacade);
	computerFacade->start(computerFacade);
	delete (ComputerFacade, computerFacade);
	return 0;
}
