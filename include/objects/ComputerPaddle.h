#pragma once

#include <SFML/Graphics.hpp>

#include "Paddle.h"
#include "RandomNumberGenerator.h"
#include "Difficulty.h"

#include <iostream>

class ComputerPaddle : public Paddle
{
private:
    // variables
    RandomNumberGenerator rng;
    int difficulty;

public:
    // constructors
    ComputerPaddle();
    ComputerPaddle(Difficulty difficulty);

    // methods
    void handleMovement(sf::Vector2u windowSize, sf::Vector2f) override;
};