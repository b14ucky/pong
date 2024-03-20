#pragma once

#include <SFML/Graphics.hpp>

#include "Paddle.h"

class UserPaddle : public Paddle
{
public:
    // constructor
    UserPaddle();

    // methods
    void handleMovement(sf::Vector2u windowSize, sf::Vector2f ballPosition) override;
};