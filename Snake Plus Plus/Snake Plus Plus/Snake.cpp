#include "Snake.h"



Snake::Snake(std::vector<SnakePart*> snakeParts)
{
}


Snake::~Snake()
{
}

void Snake::Update(sf::Time deltaTime)
{
	// Sets the direction based on what key we just pressed
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		parts[0]->SetDirection(-1, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		parts[0]->SetDirection(1, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		parts[0]->SetDirection(0, -1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		parts[0]->SetDirection(0, 1);
	}
}
