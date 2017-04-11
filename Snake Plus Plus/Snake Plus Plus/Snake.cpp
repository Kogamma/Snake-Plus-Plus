#include "Snake.h"
#include <iostream>

Snake::Snake(int startSize, std::vector<SnakePart*>& snakeParts)
{
    size = startSize;
    orgSize = size;

    // Sets the parts vector and also clears it since we wan't an empty vector
    //parts = snakeParts;

    // Creates the first SnakePart, the head, and adds it to the vector
    parts.push_back(new SnakePart(
        sf::Vector2i(Sizes().gridSize / 2, Sizes().gridSize / 2),
        sf::Vector2i(1,0)));

    // Sets starting values for the countdown variables
    countdown = 0.1f;
    timer = countdown;

    newDir = sf::Vector2i(0, 0);
}


Snake::~Snake()
{
}

void Snake::Update(const sf::Time deltaTime)
{
    // The time since the last frame
    float dt = deltaTime.asSeconds();
   
    if (!hasPressedKey)
    {
        // Assumes by default that we have pressed a key
        hasPressedKey = true;

        // Sets the new direction of the first SnakePart, the head, based on what key we just pressed
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            newDir = sf::Vector2i(-1, 0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            newDir = sf::Vector2i(1, 0);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            newDir = sf::Vector2i(0, -1);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            newDir = sf::Vector2i(0, 1);
        }
        else
        {
            // If we get here we haven't pressed a key
            hasPressedKey = false;
        }

        if (parts[0]->GetLastDirection() == sf::Vector2i(0, 0))
        {
            if (hasPressedKey)
            {
                parts.front()->SetLastDirection(newDir);
                addPieces = true;
            }
        }
    }

    // Checks if we have counted down the timer
    if (timer <= 0)
    {
        // Resets timer
        timer = countdown;

        // Allows input again 
        hasPressedKey = false;
        
        // Checks first if we haven't moved yet
        if(parts.front()->GetLastDirection() != sf::Vector2i(0,0))
            // If we have, we apply the newDir
            parts.front()->SetDirection(newDir);
        else
            // If we have not we continue to stand still
            parts.front()->SetDirection(0,0);
        // Updates the first SnakePart after we have checked for input and set the direction
        // Also checks if we move outside the screen
        isGameOver = parts.front()->MoveForward();

        // Checks if the game is over
        if (!isGameOver)
        {
            // Checks if we collided with ourselves
            isGameOver = CheckSelfCollision();

            // Checks again if the game is over
            if (!isGameOver)
            {
                // Iterates all the SnakeParts except the first one
                for (int i = 1; i < (int)parts.size(); i++)
                {
                    // Sets the traveling direction of the SnakePart to that of the one before it
                    parts[i]->SetDirection(parts[i - 1]->GetLastDirection());
                    
                    // Moves the SnakePart forward
                    parts[i]->MoveForward();
                }
            }
        }
        
        // Uses the sizes value to see if we have reached the desired starting size of the snake yet.
        if (size > 1 && addPieces)
        {
            size--;
            AddSnakePart();
            // When we reset the game we want to spawn new pieces again and we have to
            // set addPieces to false, otherwise we will spawn all the pieces on top of 
            // each other at once
            if (size <= 1)
                addPieces = false;
        }
    }
    else
    {
        // Counts down the timer
        timer -= dt;
    }

    if (isGameOver)
    {
        for (auto it = parts.begin(); it != parts.end(); it++)
        {
            (*it)->SetColor(sf::Color::Red);
        }
    }
}

// Iterates all the SnakeParts and draw them
void Snake::DrawSnake(sf::RenderWindow& window)
{
    for (auto it = parts.begin(); it != parts.end(); it++)
    {
        (*it)->Draw(window);
    }
}

// Inserts a new SnakePart in front of the first one
void Snake::AddSnakePart()
{   
    sf::Vector2i lastPartLastDir = parts.back()->GetLastDirection();

    // Creates a new SnakePart based on the SnakePart in the back of the parts vector
    parts.push_back(new SnakePart(parts.back()->GetGridPosition() - parts.back()->GetDirection(),
        lastPartLastDir));

    parts.back()->SetLastDirection(lastPartLastDir);
}

// Gets the grid position of the specified SnakePart and returns it
sf::Vector2i Snake::GetSnakePartPosition(int index) const
{
    return parts[index]->GetGridPosition();
}

// Iterates through all the SnakeParts, gets their gridpositions and then returns them
std::vector<sf::Vector2i*> Snake::GetAllPositions() const 
{
    std::vector<sf::Vector2i*> positions;

    sf::Vector2i* newPos;

    for (auto it = parts.begin(); it != parts.end(); it++)
    {
        newPos = &sf::Vector2i((*it)->GetGridPosition());
        positions.push_back(newPos);
    }
    
    return positions;
}

// Checks if the snake head collided with another part
bool Snake::CheckSelfCollision()
{
    bool collided = false;

    // Iterates all the parts except for the first one; the head.
    for (auto it = parts.begin() + 1; it != parts.end(); it++)
    {
        // If the head is on the same position as another SnakePart
        if (parts.front()->GetGridPosition() == (*it)->GetGridPosition())
        {
            // In that case, says that we collided we something and breaks out of the loop
            collided = true;

            break;
        }
        else
            collided = false;
    }
    return collided;
}

// Returns if the game is over
bool Snake::GetGameOver() const
{
    return isGameOver;
}

void Snake::Reset()
{
    // Resets the size to our original size
    size = orgSize;
    
    // Deletes all the elements in the vector and removes the elements from the vector
    for (auto it = parts.begin(); it != parts.end();)
    {
        delete (*it);

        it = parts.erase(it);
    }

    // Creates the original SnakePart in the middle of the screen again
    parts.push_back(new SnakePart(
        sf::Vector2i(Sizes().gridSize / 2, Sizes().gridSize / 2),
        sf::Vector2i(0, 0)));

    // Resets timer
    timer = countdown;

    parts.front()->SetColor(sf::Color::White);

    // Sets the game to not be over
    isGameOver = false;
}