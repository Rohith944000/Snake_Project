#pragma once
#include"ConsoleReader.h"
#include"ConsoleWriter.h"
#include"Apple.h"
#include"Map.h"
#include"Snake.h"
#include"Player.h"
#include "Time.hh"
#include<string>

using std::string;
using namespace utility;
class GameManager
{
private:
	Map map;
	Snake snake;
	Apple apple;
	Player player;
	ConsoleWriter writer;
	ConsoleReader reader;
	bool gameOver;
	Time time1;

public:
	GameManager();
	void start();
	
private:
	void initialize();
	void update();
	void gameContinueCheck(bool gameContinue);
	void displayApple();
	bool hasSnakeCoordinates(Coordinate position);
	bool appleEaten();
	void displayScoreboard();
};

