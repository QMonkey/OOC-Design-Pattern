#include <stdio.h>

#include "base.h"
#include "imemento.h"
#include "calculator.h"
#include "calculator_memento_manager.h"

int main()
{
	Calculator* calculator = new (Calculator);
	CalculatorMementoManager* calculatorMementoManager = new (CalculatorMementoManager);

	calculator->add(calculator, 10, 11);
	printf("Result:\t%d\n", calculator->getResult(calculator));

	IMemento* imemento = calculator->createMemento(calculator);
	calculatorMementoManager->setMemento(calculatorMementoManager, imemento);

	calculator->minus(calculator, 11, 10);
	printf("Result:\t%d\n", calculator->getResult(calculator));

	imemento = calculatorMementoManager->getMemento(calculatorMementoManager);
	calculator->setMemento(calculator, imemento);
	printf("Result:\t%d\n", calculator->getResult(calculator));

	delete (CalculatorMementoManager, calculatorMementoManager);
	delete (Calculator, calculator);
	return 0;
}
