#pragma once
#include <SFML\Graphics.hpp>
#include "Sizes.h"

class GridShape
{
public:
    GridShape();
    ~GridShape();

    // Sets the position on the grid
    void SetGridPosition(sf::Vector2i pos);

    // Gets the position on the grid
    sf::Vector2i GetGridPosition() const;

    // Converts the grid position to a "real" position
    void UpdateShapePosition();
    // Gets the position of the shape
    sf::Vector2f GetShapePosition();

    void Draw(sf::RenderWindow& window);

    void SetColor(sf::Color color);
    void SetColor(int r, int g, int b, int a);

protected:
    // The shape to represent the SnakePart
    sf::RectangleShape shape;

private:
    // The position of the SnakePart
    sf::Vector2i gridPos;
};

