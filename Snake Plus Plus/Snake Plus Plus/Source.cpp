#include <iostream>
#include <vector>
#include "SnakePart.h"
#include "Snake.h"
#include "Pickup.h"
#include "Sizes.h"
#include <SFML\Graphics.hpp>


int main()
{
	// seeds our rand()
	srand(time(NULL));
    
    // Counts the time
    sf::Clock time;
    // Counts time since the last frame
    sf::Time currentTime;

	sf::RenderWindow window(sf::VideoMode(Sizes().screenSize, Sizes().screenSize), "Snake Plus Plus");

    // The vector holding all the snakeParts the Snake consists of
    std::vector<SnakePart*> snakeParts;
   
    // Creates a new Snake with 3 parts and a reference to the snakeParts vector 
    Snake* snake = new Snake(3, snakeParts);;
    
    // Creates a new pickup
    Pickup* pickUp = new Pickup();

start: // subroutine we call when the game is restarted   

    // Gives the pickUp a new, random position when we start the game
    pickUp->NewPosition(snake->GetAllPositions());

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

        // If we press 'R', the game resets
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        {   
            snake->Reset();
            
            goto start;
        }
        
        // Checks if we haven't got GAME OVER
        if (!snake->GetGameOver())
        {
            // Starts counting the time
            currentTime = time.restart();

            // Updates the Snake using the time since the last frame
            snake->Update(currentTime);

            // Checks if the pickup collided with the first part of the snake, the head
            if (pickUp->CheckCollision(snake->GetSnakePartPosition(0)))
            {
                // If so, add a new part...
                snake->AddSnakePart();
                // ... and give the pickup a new, random position
                pickUp->NewPosition(snake->GetAllPositions());
            }
        }
        // Calls the draw method in the snake
        snake->DrawSnake(window);
        pickUp->Draw(window);

		window.display();
	}

	return 0;
}