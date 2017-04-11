#pragma once
#include <SFML\Graphics.hpp>
#include "GridShape.h"

class SnakePart : public GridShape
{
public:
	SnakePart(sf::Vector2i position, sf::Vector2i direction);
	~SnakePart();

	// Updates the SnakePart
	bool MoveForward();

	// Method for changing the direction of the snakepart
	void SetDirection(sf::Vector2i dir);
	void SetDirection(int x, int y);

    // Gets the traveling direction of the SnakePart
    sf::Vector2i GetDirection() const;

    // Sets the traveling direction of the SnakePart the last frame
    void SetLastDirection(sf::Vector2i newLastDir);
    
    // Gets the traveling direction of the SnakePart the last frame
    sf::Vector2i GetLastDirection() const;

private:
	// The direction the SnakePart is traveling in
	sf::Vector2i dir;
    // The direction the SnakeParts WAS traveling in the last fram
    sf::Vector2i lastDir;
};

