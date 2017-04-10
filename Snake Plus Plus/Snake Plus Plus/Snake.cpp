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
		dir.y = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		dir.x = 1;
		dir.y = 0;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		dir.x = 0;
		dir.y = -1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		dir.x = 0;
		dir.y = 1;
	}
}
