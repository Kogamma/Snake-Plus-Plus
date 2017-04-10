#include <iostream>
#include <vector>
#include "SnakePart.h"
#include "Pickup.h"
#include <SFML\Graphics.hpp>


int main()
{
	// seeds our rand()
	srand(time(NULL));

	sf::RenderWindow window(sf::VideoMode(800, 800), "Snake Plus Plus");
	
	// How many tiles there will be in the grid
	static sf::Vector2i gridSize(40,40);

	// Tiles will always be square, thereby they only need one specified size
	static float tileSize = float(window.getSize().x / gridSize.x);

	sf::RectangleShape boxes[40][40];

	for (int i = 0; i < gridSize.x; i++)
	{
		for (int j = 0; j < gridSize.y; j++)
		{
			sf::RectangleShape newBox(sf::Vector2f(tileSize, tileSize));
			sf::Color newRandomColor(rand() % 255 + 1, rand() % 255 + 1, rand() % 255 + 1, 255);
			newBox.setFillColor(newRandomColor);
			newBox.setPosition(tileSize * i, tileSize * j);
			boxes[i][j] = newBox;
		}
	}
    
	// A vector that holds all the SnakeParts that make up the whole snake
	std::vector<SnakePart*> snakeParts;
    snakeParts.push_back(new SnakePart(sf::Vector2i((int)(gridSize.x / 2), (int)(gridSize.y / 2)), sf::Vector2i(0, 0)));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		for (int i = 0; i < gridSize.x; i++)
		{
			for (int j = 0; j < gridSize.y; j++)
			{
				window.draw(boxes[i][j]);
			}
		}
		window.display();
	}

	return 0;
}