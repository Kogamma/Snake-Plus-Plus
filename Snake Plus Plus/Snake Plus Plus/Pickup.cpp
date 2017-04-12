#include "Pickup.h"

Pickup::Pickup()
{
    shape.setFillColor(sf::Color::Green);
}


Pickup::~Pickup()
{
}

// Gives the pickup a new, random position while also avoiding other objects
void Pickup::NewPosition(std::vector<sf::Vector2i*> gridPositions)
{
    sf::Vector2i newPos;

    bool canSetPos = false;

    while (!canSetPos)
    {
        // Sets new random values on the grid based on the gridSize variable in Sizes
        newPos.x = rand() % (Sizes().gridSize - 1) + 0;
        newPos.y = rand() % (Sizes().gridSize - 1) + 0;

        // Iterates through all of the positions we sent here
        for (auto it = gridPositions.begin(); it != gridPositions.end(); it++)
        {
            // Checks if the newPosition is not the same as one of the other positions
            if (newPos.x == (*it)->x && newPos.y == (*it)->y)
			{
				canSetPos = false;
				break;
			}
            // If there already is something on this position we break the loop and get a new random position
            else
				canSetPos = true;
        }
    }

    SetGridPosition(newPos);
}

// Checks if the pickup is "colliding" with something, i.e is on the same position
bool Pickup::CheckCollision(const sf::Vector2i& collisionPos)
{
    // Checks if the pickup and the other object is on the same position
    if (collisionPos == GetGridPosition())
        return true;

    return false;
}
