#include "Paddle.h"

// constructor

Paddle::Paddle()
{
    this->height = 130;
    this->width = 30;
    this->moveSpeed = 2.5f;
    this->setSize(sf::Vector2f(this->width, this->height));
    this->setFillColor(sf::Color::White);
}

// methods

void Paddle::draw(sf::RenderWindow &window)
{
    window.draw(*this);
}

void Paddle::moveUp()
{
    this->move(sf::Vector2f(0, -this->moveSpeed));
}

void Paddle::moveDown()
{
    this->move(sf::Vector2f(0, this->moveSpeed));
}