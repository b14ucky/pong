#include "GameState.h"

// init methods

void GameState::initPlayers()
{
    /*
        Initializes the players of the Game class.
    */
    this->playerLeft = Player(true, this->font);
    this->playerRight = Player(false, this->font);
}

void GameState::initGameObjects()
{
    /*
        Initializes the game objects of the Game class. Sets their positions.
    */
    int windowSizeX = this->window->getSize().x;
    int windowSizeY = this->window->getSize().y;
    this->playerLeft.paddle.setPosition(50, windowSizeY / 2 - this->playerLeft.paddle.getSize().y / 2);
    this->playerRight.paddle.setPosition(windowSizeX - 50 - this->playerRight.paddle.getSize().x, windowSizeY / 2 - this->playerRight.paddle.getSize().y / 2);
    this->ball.setInitPosition(sf::Vector2f(windowSizeX / 2.f, windowSizeY / 2.f));
    this->ball.setPointCount(100);
    this->ball.reset();
}

// constructors/destructors

GameState::GameState(sf::RenderWindow *window, sf::Font &font)
{
    /*
        The constructor of the Game class. Calls all the init functions to initialize the game.
    */
    this->window = window;
    this->font = font;
    this->initPlayers();
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
        if (this->playerLeft.paddle.getPosition().y > 0)
        {
            this->playerLeft.paddle.moveUp();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        if (this->playerLeft.paddle.getPosition().y + this->playerLeft.paddle.getSize().y < this->window->getSize().y)
        {
            this->playerLeft.paddle.moveDown();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (this->playerRight.paddle.getPosition().y > 0)
        {
            this->playerRight.paddle.moveUp();
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if (this->playerRight.paddle.getPosition().y + this->playerRight.paddle.getSize().y < this->window->getSize().y)
        {
            this->playerRight.paddle.moveDown();
        }
    }
}

// main update/render functions

void GameState::update()
{
    /*
        Updates game objects before rendering them to the window.
    */
    this->ball.handleCollisions(this->playerLeft, this->playerRight, this->window);
    this->ball.handleMovement();

    this->handleInput();
}

void GameState::render()
{
    /*
        Renders game objects to the window. Clears the window at the beginning and sets the background color to black.
    */
    this->playerLeft.paddle.draw(*this->window);
    this->playerRight.paddle.draw(*this->window);
    this->ball.draw(*this->window);
    this->playerLeft.renderScore(this->window);
    this->playerRight.renderScore(this->window);
}