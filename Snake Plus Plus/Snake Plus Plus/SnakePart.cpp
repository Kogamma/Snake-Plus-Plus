#include "SnakePart.h"

SnakePart::SnakePart(sf::Vector2i position, sf::Vector2i direction)
{
	dir = direction;
}


SnakePart::~SnakePart()
{
}

void SnakePart::UpdatePosition()
{

}

void SnakePart::SetDirection(sf::Vector2i direction)
{
	SetDirection(direction.x, direction.y);
}

void SnakePart::SetDirection(int x, int y)
{
	if (abs(x) != abs(dir.x))
		dir.x = x;
	if (abs(y) != abs(dir.y))
		dir.y = y;
}
