#pragma once
#include <SFML\Graphics.hpp>
#include "GridShape.h"

class Pickup : public GridShape
{
public:
	Pickup();
	~Pickup();

    // Method for giving the pickup a new, random position
    void NewPosition(std::vector<sf::Vector2i*> gridPositions);

    // Checks if we collided with another position
    bool CheckCollision(const sf::Vector2i& collisionPos);

private:

};

