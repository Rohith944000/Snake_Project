#pragma once
#include"Position.h"
#include<time.h>
using namespace utility;

class Apple
{
private:
	Position applePosition;

public:
	Apple();
	void setPosition();
	Position getPosition();
	int randomNumberGenerator(int min, int max);
	
};

