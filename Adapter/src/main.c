#include <stdio.h>

#include "base.h"
#include "itarget.h"
#include "target.h"
#include "iadaptee.h"
#include "adaptee.h"
#include "adapter.h"

int main()
{
	Adaptee* adaptee = new (Adaptee);
	IAdaptee* iadaptee = &adaptee->iadaptee;

	Adapter* adapter = new (Adapter, iadaptee);
	Target* target = new (Target);

	ITarget* itarget = &adapter->itarget;
	printf("%ld\n", itarget->powerOf2(itarget, 10));

	itarget = &target->itarget;
	printf("%ld\n", itarget->powerOf2(itarget, 10));

	delete (Adapter, adapter);
	delete (Target, target);
	delete (Adaptee, adaptee);

	return 0;
}
