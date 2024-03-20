#include "Paddle.h"

// constructor

Paddle::Paddle()
{
    /*
        The constructor of the Paddle class. Initializes the paddle's size, color and move speed.
    */
    this->moveSpeed = 2.5f;
    this->setSize(sf::Vector2f(30, 130));
    this->setFillColor(sf::Color::White);
    this->hitbox.setSize(sf::Vector2f(2.f, 130));
    this->hitbox.setFillColor(sf::Color::Red);
}

// methods

void Paddle::draw(sf::RenderWindow &window)
{
    this->hitbox.setPosition(this->hitboxPositionX, this->getPosition().y);
    window.draw(*this);
    window.draw(this->hitbox);
}

void Paddle::moveUp()
{
    this->move(sf::Vector2f(0, -this->moveSpeed));
    this->hitbox.move(sf::Vector2f(0, -this->moveSpeed));
}

void Paddle::moveDown()
{
    this->move(sf::Vector2f(0, this->moveSpeed));
    this->hitbox.move(sf::Vector2f(0, this->moveSpeed));
}

void Paddle::setInitPosition(sf::Vector2f initPosition, float hitboxPositionX)
{
    this->initPosition = initPosition;
    this->setPosition(initPosition);
    this->hitboxPositionX = hitboxPositionX;
    this->hitbox.setPosition(this->hitboxPositionX, this->initPosition.y);
}

void Paddle::handleMovement(float windowSizeY) {}

// getters

sf::FloatRect Paddle::getHitboxBounds()
{
    return this->hitbox.getGlobalBounds();
}

// settters

void Paddle::setMoveSpeed(float moveSpeed)
{
    this->moveSpeed = moveSpeed;
}