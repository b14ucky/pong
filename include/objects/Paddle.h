#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Paddle : public sf::RectangleShape
{
private:
    // variables
    int height;
    int width;
    float moveSpeed;
    sf::RectangleShape hitbox;
    float hitboxPositionX;
    sf::Vector2f initPosition;

public:
    // constructor
    Paddle();

    // methods
    void draw(sf::RenderWindow &window);
    void moveUp();
    void moveDown();
    void setInitPosition(sf::Vector2f initPosition, float hitboxPositionX);

    // getters
    sf::FloatRect getHitboxBounds();
};