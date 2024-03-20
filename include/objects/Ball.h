#pragma once

#include <SFML/Graphics.hpp>

#include "Player.h"
#include "HumanPlayer.h"

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
    template <typename T1, typename T2>
    void handleCollisions(T1 &playerLeft, T2 &playerRight, sf::RenderWindow *window);
    void handleMovement();
    void handleOutOfBounds();
};
