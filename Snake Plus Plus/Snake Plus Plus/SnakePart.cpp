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
	dir = direction;
}

void SnakePart::SetDirection(int x, int y)
{
	dir = sf::Vector2i(x, y);
}
