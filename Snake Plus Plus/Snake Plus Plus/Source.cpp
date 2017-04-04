#include <iostream>
#include <vector>
#include "SnakePart.h"
#include "Pickup.h"
#include <SFML\Graphics.hpp>

using namespace std;


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
			sf::Color newRandomColor(rand() % (0, 255) + 255, rand() % (0, 255) + 255, rand() % (0, 255) + 255, 255);
			newBox.setFillColor(newRandomColor);
			newBox.setPosition(tileSize * i, tileSize * j);
			boxes[i][j] = newBox;
		}
	}

	// A vector that holds all the SnakeParts that make up the whole snake
	vector<SnakePart*> snake;

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