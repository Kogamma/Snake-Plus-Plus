#pragma once
#include "SnakePart.h"
#include "Sizes.h"
#include <vector>


class Snake
{
public:
    Snake(int startSize, std::vector<SnakePart*>& snakeParts);
	~Snake();

	void Update(const sf::Time deltaTime);

    // Draws all the SnakeParts
    void DrawSnake(sf::RenderWindow& window);

    // Adds a new element to the parts vector
    void AddSnakePart();

    // Gets position of a SnakePart at specified posittion
    sf::Vector2i GetSnakePartPosition(int index) const;

    // Gets all the positions of the SnakeParts
    std::vector<sf::Vector2i*> GetAllPositions() const;

    // Checks if the 'head' of the snake collided with it self
    bool CheckSelfCollision();

    // Returns if the game is over
    bool GetGameOver() const;

    // Resets the snake to it's starting value
    void Reset();

private:
    // All the SnakeParts in the game that we update in this class
	std::vector<SnakePart*> parts;

    // How many pieces we will spawn in the beginning of the game
    int size;
    // The original value of size, used when resetting
    int orgSize;

    // If we should add the starting pieces to the snake
    bool addPieces = false;

    // If we pressed a key this frame
    bool hasPressedKey = true;    
    // Used to store what direction we chose with our input
    sf::Vector2i newDir;

    // Variables for counting down time for updating the position of the SnakeParts
    float countdown;
    float timer;

    bool isGameOver = false;
};

