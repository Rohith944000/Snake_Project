#include "Apple.h"

Apple::Apple()
	: applePosition(randomNumberGenerator(1,99),randomNumberGenerator(1,29))
{
}

void Apple::setPosition()
{
	int x = randomNumberGenerator(1, 99);
	int y = randomNumberGenerator(1, 29);
	applePosition = Position(x, y);
}

Position Apple::getPosition()
{
	return applePosition;
}

int Apple::randomNumberGenerator(int min, int max)
{
	srand(time(0));
	int randomGeneratedNumber = rand();
	int finalVal = (randomGeneratedNumber % (max - min )) + min;
	
	return finalVal;
}

