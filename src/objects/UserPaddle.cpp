#include "UserPaddle.h"

// constructor
UserPaddle::UserPaddle()
{
    /*
        The constructor of the Paddle class. Initializes the paddle's size, color and move speed.
    */
}

// methods

void UserPaddle::handleMovement(sf::Vector2u windowSize, sf::Vector2f ballPosition)
{
    /*
        Handles the movement of the user paddle.
    */
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (this->getPosition().y > 0)
        {
            this->moveUp();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if (this->getPosition().y + this->getSize().y < windowSize.y)
        {
            this->moveDown();
        }
    }
}