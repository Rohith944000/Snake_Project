#pragma once
#include<vector>
#include"Coordinate.h"
#include"ConsoleWriter.h"
#include<string>
using std::string;
using namespace utility;
using std::vector;

class Snake
{
private:

	vector<Coordinate>snakes;
	int length;
	string direction;
	Coordinate lastCoordinate = Coordinate(0,0);
public:
	Snake();
	int getLength();
	string getDirection();
	vector<Coordinate>getSnakeCordinates();
	void clearSnake();
	void drawSnake();
	bool moveForward();
	bool moveUpward();
	bool moveDownward();
	bool moveBackward();
	bool collide();
	void addPosition();
	void setLength();
private:
	vector<Coordinate> createPositions();
	void displaySnake(char character);
};

