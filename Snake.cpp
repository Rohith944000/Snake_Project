#include "Snake.h"

Snake::Snake()
	:length(10),direction("Forward"),snakes(createPositions())
{
}


int Snake::getLength()
{
	return snakes.size();
}

string Snake::getDirection()
{
	return direction;
}

vector<Coordinate> Snake::getSnakeCordinates()
{
	return snakes;
}

void Snake::displaySnake(char character)
{
	ConsoleWriter writer = ConsoleWriter();
	for (int i = 0; i < snakes.size(); i++) {
		writer.setCharacterAtPosition(snakes[i], character);
	}
}

void Snake::clearSnake()
{
	displaySnake(' ');
}

void Snake::drawSnake()
{
	displaySnake('0');
}

bool Snake::moveForward()
{
	if(snakes[0].X == 99){

		return false;
	}
	else {
		lastCoordinate = snakes[getLength() - 1];
		for (int i = getLength() - 1; i > 0; i--) {
			snakes[i] = snakes[i - 1];
		}
		snakes[0].X = snakes[0].X + 1;

		if (collide()) {
			return false;
		}
		
		this->direction = "Forward";
		return true;
	}
	
}

bool Snake::moveUpward()
{
	if (snakes[0].Y == 1) {

		return false;
	}
	else {
		lastCoordinate = snakes[getLength() - 1];
		for (int i = getLength() - 1; i > 0; i--) {
			snakes[i] = snakes[i - 1];
		}
		snakes[0].Y = snakes[0].Y - 1;

		if (collide()) {
			return false;
		}
		
		this->direction = "Up";
		return true;
	}
	
}

bool Snake::moveDownward()
{
	if (snakes[0].Y == 29) {

		return false;
	}
	else {
		lastCoordinate = snakes[getLength() - 1];
		for (int i = getLength() - 1; i > 0; i--) {
			snakes[i] = snakes[i - 1];
		}
		snakes[0].Y = snakes[0].Y + 1;

		if (collide()) {
			return false;
		}
		this->direction = "Down";
		return true;
	}
}

bool Snake::moveBackward()
{
	if (snakes[0].X == 1) {

		return false;
	}
	else {
		lastCoordinate = snakes[getLength() - 1];
		for (int i = getLength() - 1; i > 0; i--) {
			snakes[i] = snakes[i - 1];
		}
		snakes[0].X = snakes[0].X - 1;

		if (collide()) {
			return false;
		}
		this->direction = "Backward";
		return true;
	}
	
}

bool Snake::collide()
{
	for (int i = 1; i < snakes.size(); i++) {
		if (snakes[0] == snakes[i]) {
			return true;
		}
	}
	return false;
}

void Snake::addPosition()
{
	Coordinate newCordinate = lastCoordinate;
	snakes.push_back(newCordinate);
	setLength();
}

void Snake::setLength()
{
	this->length = getLength() + 1;
}

vector<Coordinate> Snake::createPositions()
{
	return vector<Coordinate>
	{
		Coordinate(50, 15), Coordinate(49, 15), Coordinate(48, 15), Coordinate(47, 15), Coordinate(46, 15), Coordinate(45, 15), Coordinate(44, 15),
		Coordinate(43, 15), Coordinate(42, 15), Coordinate(41, 15)
	};
}
