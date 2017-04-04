#pragma once
#include <SFML\Graphics.hpp>

class SnakePart
{
public:
	SnakePart(sf::Vector2f position, sf::Vector2i direction);
	~SnakePart();

	void Update(sf::Time deltaTime);

	void SetDirection(sf::Vector2i dir);

private:
	// The direction the SnakePart is traveling in
	sf::Vector2i dir;
};

