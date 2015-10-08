#include "base.h"
#include "itravel_strategy.h"
#include "airplane_strategy.h"
#include "train_strategy.h"
#include "person.h"

int main()
{
	TrainStrategy* trainStrategy = new (TrainStrategy);
	ITravelStrategy* itravelStrategy = &trainStrategy->itravelStrategy;
	Person* person = new (Person, itravelStrategy);
	person->travel(person);

	AirplaneStrategy* airplaneStrategy = new (AirplaneStrategy);
	itravelStrategy = &airplaneStrategy->itravelStrategy;
	person->setTravelStrategy(person, itravelStrategy);
	person->travel(person);

	delete (Person, person);
	delete (AirplaneStrategy, airplaneStrategy);
	delete (TrainStrategy, trainStrategy);

	return 0;
}
