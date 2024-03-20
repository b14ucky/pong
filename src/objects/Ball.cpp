#include "Ball.h"

// constructor
Ball::Ball()
{
    this->initMoveSpeed = 2.75f;
    this->setRadius(15);
    this->setFillColor(sf::Color::White);
    this->setOrigin(this->getRadius(), this->getRadius());
    this->moveSpeed = this->initMoveSpeed;
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
    this->moveSpeed = this->initMoveSpeed;
}

void Ball::setInitPosition(sf::Vector2f position)
{
    this->initPosition = position;
}

template <typename T1, typename T2>
void Ball::handleCollisions(T1 &playerLeft, T2 &playerRight, sf::RenderWindow *window)
{
    /*
        Moves the ball left or right depending on the ballDirection variable.
        If the ball hits one of the paddles, it changes the direction nd adjusts the deviation rate.
        If the ball hits the top or bottom wall, it changes the deviation rate so the ball bounces off the wall.
        If the ball hits left or right wall, it changes the direction and resets the ball position to the center
        of the window and appends the score of the player.
    */
    sf::Vector2f ballPosition = this->getPosition();
    sf::Vector2f paddleLeftPosition = playerLeft.paddle.getPosition();
    sf::Vector2f paddleRightPosition = playerRight.paddle.getPosition();

    if (this->getGlobalBounds().intersects(playerLeft.paddle.getHitboxBounds()))
    {
        this->direction = true;
        this->deviationRate = (ballPosition.y - paddleLeftPosition.y - playerLeft.paddle.getSize().y / 2) / playerLeft.paddle.getSize().y / 0.5;
        this->moveSpeed += 0.05f;
    }
    if (this->getGlobalBounds().intersects(playerRight.paddle.getHitboxBounds()))
    {
        this->direction = false;
        this->deviationRate = (ballPosition.y - paddleRightPosition.y - playerRight.paddle.getSize().y / 2) / playerRight.paddle.getSize().y / 0.5;
        this->moveSpeed += 0.05f;
    }
    if (ballPosition.y - this->getRadius() < 0 || ballPosition.y + this->getRadius() > window->getSize().y)
    {
        this->deviationRate = -this->deviationRate;
    }
    if (ballPosition.x + this->getRadius() < 0)
    {
        this->handleOutOfBounds();
        playerRight.appendScore();
    }
    else if (ballPosition.x - this->getRadius() > window->getSize().x)
    {
        this->handleOutOfBounds();
        playerLeft.appendScore();
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

void Ball::handleOutOfBounds()
{
    /*
        If the ball hits left or right wall, it changes the direction and resets the ball position to the center of the window.
    */
    this->direction = !this->direction;
    this->reset();
    this->deviationRate = 0;
}

template void Ball::handleCollisions(HumanPlayer &playerLeft, HumanPlayer &playerRight, sf::RenderWindow *window);
// template void Ball::handleCollisions(ComputerPlayer &playerLeft, ComputerPlayer &playerRight, sf::RenderWindow *window);