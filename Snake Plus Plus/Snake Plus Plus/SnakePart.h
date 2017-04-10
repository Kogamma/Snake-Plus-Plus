#pragma once
#include <SFML\Graphics.hpp>

class SnakePart
{
public:
	SnakePart(sf::Vector2i position, sf::Vector2i direction);
	~SnakePart();

	// Updates the SnakePart
	void UpdatePosition();

	// Method for changing the direction of the snakepart
	void SetDirection(sf::Vector2i dir);
	void SetDirection(int x, int y);

private:
	// The direction the SnakePart is traveling in
	sf::Vector2i dir;

    sf::Vector2i lastPos;
};

