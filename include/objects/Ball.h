#pragma once

#include <SFML/Graphics.hpp>

#include "Player.h"

class Ball : public sf::CircleShape
{
private:
    // variables
    float moveSpeed;
    float initMoveSpeed;
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
    void handleCollisions(Player &playerLeft, Player &playerRight, sf::RenderWindow *window);
    void handleMovement();
    void handleOutOfBounds();
};