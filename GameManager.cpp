#include "GameManager.h"

GameManager::GameManager()
	:map(),snake(),apple(),player(),writer(),reader(),time1(Time::getNow()),gameOver(false)
{
}

void GameManager::start()
{
	
	initialize();
	while (!reader.isEscapePressed() && !gameOver)
	{
		update();
	}
	writer.pause();
}



void GameManager::initialize()
{
	map.setGameBoundaries();
	snake.drawSnake();
	displayApple();
	displayScoreboard();
	
}

void GameManager::update()
{
	Sleep(75);
	string direction = snake.getDirection();
	bool gameContinue = false;

	if (!reader.isUpArrowPressed() && !reader.isDownArrowPressed() && !reader.isLeftArrowPressed() && !reader.isRightArrowPressed()) 
	{
		snake.clearSnake();
		if (direction == "Forward") {
			gameContinue = snake.moveForward();
			gameContinueCheck(gameContinue);
		}
		if (direction == "Up") {
			gameContinue = snake.moveUpward();
			gameContinueCheck(gameContinue);
		}
		if (direction == "Down") {
			gameContinue = snake.moveDownward();
			gameContinueCheck(gameContinue);
		}
		if (direction == "Backward") {
			gameContinue = snake.moveBackward();
			gameContinueCheck(gameContinue);
		}
	}

	if (reader.isDownArrowPressed() && direction != "Up") {
		snake.clearSnake();
		gameContinue = snake.moveDownward();
		gameContinueCheck(gameContinue);
	}
	if (reader.isUpArrowPressed() && direction != "Down") {
		snake.clearSnake();
		gameContinue = snake.moveUpward();
		gameContinueCheck(gameContinue);
	}
	if (reader.isLeftArrowPressed() && direction != "Forward") {
		snake.clearSnake();
		gameContinue = snake.moveBackward();
		gameContinueCheck(gameContinue);
	}
	if (reader.isRightArrowPressed() && direction != "Backward") {
		snake.clearSnake();
		gameContinue = snake.moveForward();
		gameContinueCheck(gameContinue);
	}
	
	if (appleEaten()) {
		displayApple();
		snake.addPosition();
		player.setScore();
	}
	displayScoreboard();
	
}

void GameManager::gameContinueCheck(bool gameContinue)
{
	if (!gameContinue) {
		snake.drawSnake();
		Coordinate textCoordinate = Coordinate(50, 15);
		writer.setCursorPosition(textCoordinate);
		Console::writeLine("Game Over");
		this->gameOver = true;
	}
	else {
		snake.drawSnake();
	}
}

void GameManager::displayApple()
{
	apple.setPosition();
	Coordinate appleCurrentPosition = (Coordinate)(apple.getPosition());
	bool SnakeCoordinates = hasSnakeCoordinates(appleCurrentPosition);
	while (SnakeCoordinates)
	{
		apple.setPosition();
		appleCurrentPosition = (Coordinate)(apple.getPosition());
		SnakeCoordinates = hasSnakeCoordinates(appleCurrentPosition);
	}
	writer.setCharacterAtPosition(appleCurrentPosition, '*');
}

bool GameManager::hasSnakeCoordinates(Coordinate position)
{
	vector<Coordinate> snakePositions = snake.getSnakeCordinates();
	for (int i = 0; i < snakePositions.size(); i++) {
		if (position == snakePositions[i]) {
			return true;
		}
	}
	return false;
}

bool GameManager::appleEaten()
{
	vector<Coordinate> snakePositions = snake.getSnakeCordinates();
	Coordinate appleCurrentPosition = (Coordinate)(apple.getPosition());

	if (snakePositions[0] == appleCurrentPosition) {
		return true;
	}
	else {
		return false;
	}
}

void GameManager::displayScoreboard()
{
	Coordinate ScoreCoordinate = Coordinate(10, 31);
	writer.setCursorPosition(ScoreCoordinate);
	string message = "    Score = " + Strings::integerToString(player.getScore()) + "    Snake length = " + Strings::integerToString(snake.getLength())
		+ "    Time  = " + Strings::integerToString(time1.getSecondsUntil(Time::getNow())) + " Seconds";
	writer.writeLine(message);
	writer.writeLine();
}


