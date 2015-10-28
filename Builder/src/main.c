#include "base.h"
#include "icar.h"
#include "ibuilder.h"
#include "audi_car.h"
#include "benz_car.h"
#include "audi_builder.h"
#include "benz_builder.h"
#include "producer.h"

int main()
{
	AudiBuilder* audiBuilder = new (AudiBuilder);
	BenzBuilder* benzBuilder = new (BenzBuilder);
	Producer* producer = new (Producer, &audiBuilder->ibuilder);

	ICar* icar = producer->produce(producer);
	icar->run(icar);
	icar->show(icar);

	producer->setBuilder(producer, &benzBuilder->ibuilder);
	icar = producer->produce(producer);
	icar->run(icar);
	icar->show(icar);

	delete (Producer, producer);
	delete (AudiBuilder, audiBuilder);
	delete (BenzBuilder, benzBuilder);
	return 0;
}
