#include "Map.h"

Map::Map()
	:topleft(Coordinate(0,0)),bottomRight(Coordinate(100,30))
{
}

Coordinate Map::getTopleft()
{
	return topleft;
}
void Map::setGameBoundaries()
{
	writer1.setWindowSize(101, 35);
	writer1.drawRectangle(getTopleft(), getBottomRight());
	writer1.setCursorVisible(false);
}
Coordinate Map::getBottomRight()
{
	return bottomRight;
}
