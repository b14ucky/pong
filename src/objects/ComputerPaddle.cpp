#include "ComputerPaddle.h"

// constructors

ComputerPaddle::ComputerPaddle() {}

ComputerPaddle::ComputerPaddle(Difficulty difficulty)
{
    /*
        The default constructor of the AIPaddle class. Calls all the init methods to initialize the AI paddle.
    */
    this->rng = RandomNumberGenerator(0, 10);
    switch (difficulty)
    {
    case Difficulty::Easy:
        this->difficulty = 4;
        break;
    case Difficulty::Medium:
        this->difficulty = 6;
        break;
    case Difficulty::Hard:
        this->difficulty = 8;
        break;
    case Difficulty::Impossible:
        this->difficulty = 10;
        break;
    }
}

// methods

void ComputerPaddle::handleMovement(sf::Vector2u windowSize, sf::Vector2f ballPosition)
{
    /*
        Handles the movement of the AI paddle.
    */
    if (this->rng() < this->difficulty) // 4 - easy, 6 - medium, 8 - hard, 10 - impossible, !!! change to this->difficulty after menu is done !!!
    {
        if (this->getPosition().y + this->getSize().y / 2 > ballPosition.y && ballPosition.x > windowSize.y / 2 - 150)
        {
            this->moveUp();
        }
        else if (this->getPosition().y + this->getSize().y / 2 < ballPosition.y && ballPosition.x > windowSize.y / 2 - 150)
        {
            this->moveDown();
        }
        if (this->getPosition().y < 0)
        {
            this->setPosition(this->getPosition().x, 0);
        }
        if (this->getPosition().y + this->getGlobalBounds().height > windowSize.y)
        {
            this->setPosition(this->getPosition().x, windowSize.y - this->getSize().y);
        }
    }
}