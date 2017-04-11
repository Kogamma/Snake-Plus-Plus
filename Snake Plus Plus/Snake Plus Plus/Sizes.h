#pragma once
static class Sizes
{
public:
    // Disclaimer: Everything in the game is square so we only set the values in 1 dimension

    // How large the actual window resolution will be
    const int screenSize = 800;

    // How many tiles there will be on the screen
    const int gridSize = 25;

    // How big the tiles will be in the game
    const float tileSize = (float)(screenSize / gridSize);
};