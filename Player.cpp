#include "Player.h"

Player::Player()
	:score(0)
{
}

int Player::getScore()
{
	return score;
}

void Player::setScore()
{
	this->score = getScore() + 1;
}
