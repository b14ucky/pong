#include "Ball.h"

// constructor
Ball::Ball()
{
    this->setRadius(15);
    this->setFillColor(sf::Color::White);
    this->setOrigin(this->getRadius(), this->getRadius());
    this->moveSpeed = 5.0f;
}

// methods
void Ball::draw(sf::RenderWindow &window)
{
    window.draw(*this);
}

void Ball::reset()
{
    this->setPosition(this->initPosition);
    this->moveSpeed = 1.0f;
}

void Ball::setInitPosition(sf::Vector2f position)
{
    this->initPosition = position;
}

float Ball::getMoveSpeed()
{
    return this->moveSpeed;
}