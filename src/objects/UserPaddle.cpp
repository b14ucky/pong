#include "UserPaddle.h"

// constructor
UserPaddle::UserPaddle()
{
    /*
        The constructor of the Paddle class. Initializes the paddle's size, color and move speed.
    */
}

// methods

void UserPaddle::handleMovement(float windowSizeY)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (this->getPosition().y > 0)
        {
            this->moveUp();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if (this->getPosition().y + this->getSize().y < windowSizeY)
        {
            this->moveDown();
        }
    }
}