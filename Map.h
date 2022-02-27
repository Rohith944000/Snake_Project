#pragma once
#include"Coordinate.h"
#include"ConsoleWriter.h"
using namespace utility;

class Map
{
private:
	Coordinate topleft;
	Coordinate bottomRight;
	ConsoleWriter writer1;

public:
	Map();
	Coordinate getTopleft();
	Coordinate getBottomRight();
	void setGameBoundaries();
};

