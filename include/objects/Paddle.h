#pragma once

#include <SFML/Graphics.hpp>

class Paddle : public sf::RectangleShape
{
private:
    // variables
    int height;
    int width;
    float moveSpeed;
    sf::RectangleShape hitbox;

public:
    // constructor
    Paddle();

    // methods
    void draw(sf::RenderWindow &window);
    void moveUp();
    void moveDown();
};