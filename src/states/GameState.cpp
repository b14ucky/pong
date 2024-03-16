#include "GameState.h"

// init functions

void GameState::initGameObjects()
{
    /*
        Initializes the game objects of the Game class. Sets their positions.
    */
    int windowSizeX = this->window->getSize().x;
    int windowSizeY = this->window->getSize().y;
    this->paddleLeft.setPosition(50, windowSizeY / 2 - this->paddleLeft.getSize().y / 2);
    this->paddleRight.setPosition(windowSizeX - 50 - this->paddleRight.getSize().x, windowSizeY / 2 - this->paddleRight.getSize().y / 2);
    this->ball.setInitPosition(sf::Vector2f(windowSizeX / 2.f, windowSizeY / 2.f));
    this->ball.setPointCount(100);
    this->ball.reset();
}

// constructors/destructors

GameState::GameState(sf::RenderWindow *window)
{
    /*
        The constructor of the Game class. Calls all the init functions to initialize the game.
    */
    this->window = window;
    this->initGameObjects();
}

GameState::~GameState()
{
    /*
        The destructor of the Game class.
    */
}

// other functions

void GameState::handleInput()
{
    /*
        Moves the paddles up or down depending on the key pressed.
    */
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        if (this->paddleLeft.getPosition().y > 0)
        {
            this->paddleLeft.moveUp();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if (this->paddleLeft.getPosition().y + this->paddleLeft.getSize().y < this->window->getSize().y)
        {
            this->paddleLeft.moveDown();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (this->paddleRight.getPosition().y > 0)
        {
            this->paddleRight.moveUp();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if (this->paddleRight.getPosition().y + this->paddleRight.getSize().y < this->window->getSize().y)
        {
            this->paddleRight.moveDown();
        }
    }
}

// main update/render functions

void GameState::update()
{
    /*
        Updates game objects before rendering them to the window.
    */
    this->ball.handleCollisions(this->paddleLeft, this->paddleRight, *this->window);
    this->ball.handleMovement();

    this->handleInput();
}

void GameState::render()
{
    /*
        Renders game objects to the window. Clears the window at the beginning and sets the background color to black.
    */
    this->paddleLeft.draw(*this->window);
    this->paddleRight.draw(*this->window);
    this->ball.draw(*this->window);
}