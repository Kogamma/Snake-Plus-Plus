#include "SnakePart.h"
#include <iostream>

SnakePart::SnakePart(sf::Vector2i position, sf::Vector2i direction)
{
    SetGridPosition(position);

	dir = direction;
    lastDir = dir;
}


SnakePart::~SnakePart()
{
}

// Updates the position by adding the current direction of the SnakePart
bool SnakePart::MoveForward()
{
    // Creates the new position which is the current position with the current direction applied
    sf::Vector2i newPos(GetGridPosition() + dir);
    
    // If the new position is outside the screen, the game is over
    if (newPos.x < 0 || newPos.x > Sizes().gridSize - 1
        || newPos.y < 0 || newPos.y > Sizes().gridSize - 1)
    {
        return true;
    }

    SetGridPosition(newPos);

    return false;
}

void SnakePart::SetDirection(sf::Vector2i direction)
{
	SetDirection(direction.x, direction.y);
}

// Sets the direction of the SnakePart
void SnakePart::SetDirection(int x, int y)
{
    SetLastDirection(dir);

    // Doesn't allow the object to go the opposite direction
    if (x != dir.x * -1)
        dir.x = x;
    if (y != dir.y * -1)
        dir.y = y;
}

sf::Vector2i SnakePart::GetDirection() const
{
    return dir;
}

void SnakePart::SetLastDirection(sf::Vector2i newLastDir)
{
    lastDir = newLastDir;
}

sf::Vector2i SnakePart::GetLastDirection() const 
{
    return lastDir;
}

