#include "Paddle.h"

// constructor

Paddle::Paddle()
{
    /*
        The constructor of the Paddle class. Initializes the paddle's size, color and move speed.
    */
    this->height = 130;
    this->width = 30;
    this->moveSpeed = 2.5f;
    this->setSize(sf::Vector2f(this->width, this->height));
    this->setFillColor(sf::Color::White);
    this->hitbox.setSize(sf::Vector2f(2.f, this->height));
    this->hitbox.setFillColor(sf::Color::Red);
}

// methods

void Paddle::draw(sf::RenderWindow &window)
{
    this->hitbox.setPosition(this->getPosition().x + this->getSize().x / 2 - this->hitbox.getSize().x / 2, this->getPosition().y);
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
    this->hitbox.move(sf::Vector2f(0, -this->moveSpeed));
}