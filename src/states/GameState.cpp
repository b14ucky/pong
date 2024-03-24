#include "GameState.h"

// init methods

void GameState::initPlayers()
{
    /*
        Initializes the players of the Game class.
    */
    this->playerLeft = HumanPlayer(true, this->font);
    this->playerRight = ComputerPlayer(false, this->font, this->difficulty);
}

void GameState::initGameObjects()
{
    /*
        Initializes the game objects of the Game class. Sets their positions.
    */
    int windowSizeX = this->window->getSize().x;
    int windowSizeY = this->window->getSize().y;
    this->playerLeft.paddle.setInitPosition(sf::Vector2f(50, windowSizeY / 2 - this->playerLeft.paddle.getSize().y / 2), 50 + this->playerLeft.paddle.getSize().x - 2);
    this->playerRight.paddle.setInitPosition(sf::Vector2f(windowSizeX - 50 - this->playerRight.paddle.getSize().x, windowSizeY / 2 - this->playerRight.paddle.getSize().y / 2), windowSizeX - 50 - this->playerRight.paddle.getSize().x);
    this->ball.setInitPosition(sf::Vector2f(windowSizeX / 2.f, windowSizeY / 2.f));
    this->ball.setPointCount(100);
    this->ball.reset();
}

// constructors/destructors

GameState::GameState(sf::RenderWindow *window, StateManager *stateManager, sf::Font &font, Difficulty difficulty)
{
    /*
        The constructor of the Game class. Calls all the init functions to initialize the game.
    */
    this->window = window;
    this->stateManager = stateManager;
    this->font = font;
    this->difficulty = difficulty;
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
    this->playerLeft.paddle.handleMovement(this->window->getSize(), this->ball.getPosition());
    this->playerRight.paddle.handleMovement(this->window->getSize(), this->ball.getPosition());
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    // {
    //     if (this->playerLeft.paddle.getPosition().y > 0)
    //     {
    //         this->playerLeft.paddle.moveUp();
    //     }
    // }
    // if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    // {
    //     if (this->playerLeft.paddle.getPosition().y + this->playerLeft.paddle.getSize().y < this->window->getSize().y)
    //     {
    //         this->playerLeft.paddle.moveDown();
    //     }
    // }
}

// main update/render functions

void GameState::update()
{
    /*
        Updates game objects before rendering them to the window.
    */
    this->ball.handleMovement();
    this->ball.handleCollisions(this->playerLeft, this->playerRight, this->window);
    this->playerLeft.updateText();
    this->playerRight.updateText();

    if (this->ball.getGlobalBounds().intersects(this->playerLeft.paddle.getHitboxBounds()) || this->ball.getGlobalBounds().intersects(this->playerRight.paddle.getHitboxBounds()))
    {
        std::cout << "collision" << std::endl;
    }

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