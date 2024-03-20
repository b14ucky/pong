#pragma once

#include <SFML/Graphics.hpp>

#include "Paddle.h"
#include "RandomNumberGenerator.h"

#include <iostream>

class AIPaddle : public Paddle
{
private:
    // variables
    RandomNumberGenerator rng;

public:
    // constructor
    AIPaddle();

    // methods
    void handleMovement(sf::Vector2u windowSize, sf::Vector2f) override;
};