#pragma once

#include <SFML/Graphics.hpp>

#include "Paddle.h"

class Ball : public sf::CircleShape
{
private:
    // variables
    float moveSpeed;
    float moveSpeedX;
    float moveSpeedY;
    sf::Vector2f initPosition;
    float deviationRate;
    bool direction; // false - left, true - right

public:
    // constructors/destructors
    Ball();

    // methods
    void draw(sf::RenderWindow &window);
    void reset();
    void setInitPosition(sf::Vector2f position);
    void handleCollisions(Paddle paddleLeft, Paddle paddleRight, sf::RenderWindow &window);
    void handleMovement();
};