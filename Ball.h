#pragma once

#include <SFML/Graphics.hpp>

class Ball : public sf::CircleShape
{
private:
    // variables
    float moveSpeed;
    float moveSpeedX;
    float moveSpeedY;
    sf::Vector2f initPosition;

public:
    // constructors/destructors
    Ball();

    // methods
    void draw(sf::RenderWindow &window);
    void reset();
    void setInitPosition(sf::Vector2f position);
    void setMoveSpeed(float moveSpeed);
    float getMoveSpeed();
};