#include "Ball.h"

// constructor
Ball::Ball()
{
    this->setRadius(15);
    this->setFillColor(sf::Color::White);
    this->setOrigin(this->getRadius(), this->getRadius());
    this->moveSpeed = 1.75f;
    this->deviationRate = 0;
    this->direction = false; // false - left, true - right
}

// methods
void Ball::draw(sf::RenderWindow &window)
{
    window.draw(*this);
}

void Ball::reset()
{
    this->setPosition(this->initPosition);
    this->moveSpeed = 1.75f;
}

void Ball::setInitPosition(sf::Vector2f position)
{
    this->initPosition = position;
}

void Ball::handleCollisions(Paddle paddleLeft, Paddle paddleRight, sf::RenderWindow &window)
{
    /*
        Moves the ball left or right depending on the ballDirection variable.
        If the ball hits one of the paddles, it changes the direction nd adjusts the deviation rate.
        If the ball hits left or right wall, it changes the direction and resets the ball position to the center of the window.
        If the ball hits the top or bottom wall, it changes the deviation rate so the ball bounces off the wall.
    */
    sf::Vector2f ballPosition = this->getPosition();
    sf::Vector2f paddleLeftPosition = paddleLeft.getPosition();
    sf::Vector2f paddleRightPosition = paddleRight.getPosition();

    if (ballPosition.x - this->getRadius() < paddleLeftPosition.x + paddleLeft.getSize().x &&
        ballPosition.y + this->getRadius() > paddleLeftPosition.y &&
        ballPosition.y - this->getRadius() < paddleLeftPosition.y + paddleLeft.getSize().y)
    {
        this->direction = true;
        this->deviationRate = (ballPosition.y - paddleLeftPosition.y - paddleLeft.getSize().y / 2) / paddleLeft.getSize().y / 0.5;
        this->moveSpeed + 0.05f;
    }
    if (ballPosition.x + this->getRadius() > paddleRightPosition.x &&
        ballPosition.y + this->getRadius() > paddleRightPosition.y &&
        ballPosition.y - this->getRadius() < paddleRightPosition.y + paddleRight.getSize().y)
    {
        this->direction = false;
        this->deviationRate = (ballPosition.y - paddleRightPosition.y - paddleRight.getSize().y / 2) / paddleRight.getSize().y / 0.5;
        this->moveSpeed + 0.05f;
    }
    if (ballPosition.y - this->getRadius() < 0 || ballPosition.y + this->getRadius() > window.getSize().y)
    {
        this->deviationRate = -this->deviationRate;
    }
    if (ballPosition.x + this->getRadius() < 0 || ballPosition.x - this->getRadius() * 2 > window.getSize().x)
    {
        this->direction = !this->direction;
        this->reset();
        this->deviationRate = 0;
    }
}

void Ball::handleMovement()
{
    /*
        Moves the ball left or right depending on the ballDirection variable.
        Adjusts the deviation rate so the ball bounces off the paddles.
    */
    if (this->direction)
    {
        this->move(sf::Vector2f(this->moveSpeed, this->moveSpeed * this->deviationRate));
    }
    else
    {
        this->move(sf::Vector2f(-this->moveSpeed, this->moveSpeed * this->deviationRate));
    }
}