#include "GridShape.h"


GridShape::GridShape()
{
    // Sets the size of the shape based on the tileSize value in the Sizes class
    shape.setSize(sf::Vector2f(Sizes().tileSize, Sizes().tileSize));
}


GridShape::~GridShape()
{
}

void GridShape::SetGridPosition(sf::Vector2i pos)
{
    gridPos = pos;

    UpdateShapePosition();
}

// Returns the position on the grid
sf::Vector2i GridShape::GetGridPosition() const
{
    return gridPos;
}

// Sets the position of the shape based on the gridPos and tileSize
void GridShape::UpdateShapePosition()
{
    shape.setPosition(gridPos.x * Sizes().tileSize, gridPos.y * Sizes().tileSize);
}

// Gets the position of the shape, the real position instead of the grid position
sf::Vector2f GridShape::GetShapePosition()
{
    return shape.getPosition();
}

void GridShape::Draw(sf::RenderWindow& window)
{
    window.draw(shape);
}

void GridShape::SetColor(sf::Color color)
{
    shape.setFillColor(color);
}

void GridShape::SetColor(int r, int g, int b, int a)
{
    SetColor(sf::Color(r, g, b, a));
}