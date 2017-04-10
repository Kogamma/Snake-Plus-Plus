#pragma once
#include "SnakePart.h"
#include <vector>


class Snake
{
public:
	Snake(std::vector<SnakePart*> snakeParts);
	~Snake();

	void Update(sf::Time deltaTime);

private:
	std::vector<SnakePart*> parts;
};

