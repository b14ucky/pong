#include "Game.h"

// init functions

void Game::initVariables()
{
    /*
        Initializes the variables of the Game class.
    */
    this->window = nullptr;

    this->ballDirection = false; // false - left, true - right
}

void Game::initWindow()
{
    /*
        Initializes the window of the game. Sets its size, title and frame rate limit.
    */
    this->videoMode.height = 768;
    this->videoMode.width = 1024;
    this->window = new sf::RenderWindow(this->videoMode, "Pong", sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(144);
}

void Game::initGameObjects()
{
    /*
        Initializes the game objects of the Game class. Sets their positions.
    */
    int windowSizeX = this->window->getSize().x;
    int windowSizeY = this->window->getSize().y;
    this->paddleLeft.setPosition(50, windowSizeY / 2 - this->paddleLeft.getSize().y / 2);
    this->paddleRight.setPosition(windowSizeX - 50 - this->paddleRight.getSize().x, windowSizeY / 2 - this->paddleRight.getSize().y / 2);
    this->ball.setInitPosition(sf::Vector2f(windowSizeX / 2.f, windowSizeY / 2.f));
    this->ball.reset();
}

// constructors/destructors

Game::Game()
{
    /*
        The constructor of the Game class. Calls all the init functions to initialize the game.
    */
    this->initVariables();
    this->initWindow();
    this->initGameObjects();
}

Game::~Game()
{
    /*
        The destructor of the Game class. Deletes the window pointer.
    */
    delete this->window;
}

// accessors
const bool Game::running() const
{
    /*
        Returns true if the window is open, false otherwise.
    */
    return this->window->isOpen();
}

// other functions

void Game::pollEvents()
{
    /*
        Polls for events. If the window is closed, set the window to be not open.
    */
    while (this->window->pollEvent(this->event))
    {
        switch (this->event.type)
        {
        case sf::Event::Closed: // close the window if the close button is clicked
            this->window->close();
            break;
        }
    }
}

void Game::movePaddle()
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

void Game::moveBall()
{
    /*
        Moves the ball left or right depending on the ballDirection variable.
        If the ball hits one of the paddles, it changes the direction.
        If the ball hits left or right wall, it changes the direction and resets the ball position to the center of the window.
    */
    sf::Vector2f ballPosition = this->ball.getPosition();
    sf::Vector2f paddleLeftPosition = this->paddleLeft.getPosition();
    sf::Vector2f paddleRightPosition = this->paddleRight.getPosition();

    if (ballPosition.x - this->ball.getRadius() == paddleLeftPosition.x + this->paddleLeft.getSize().x &&
        ballPosition.y + this->ball.getRadius() > paddleLeftPosition.y &&
        ballPosition.y - this->ball.getRadius() < paddleLeftPosition.y + this->paddleLeft.getSize().y)
    {
        this->ballDirection = true;
    }
    if (ballPosition.x + this->ball.getRadius() == paddleRightPosition.x &&
        ballPosition.y + this->ball.getRadius() > paddleRightPosition.y &&
        ballPosition.y - this->ball.getRadius() < paddleRightPosition.y + this->paddleRight.getSize().y)
    {
        this->ballDirection = false;
    }
    if (ballPosition.x + this->ball.getRadius() < 0 || ballPosition.x - this->ball.getRadius() * 2 > this->window->getSize().x)
    {
        this->ballDirection = !this->ballDirection;
        this->ball.reset();
    }
    if (this->ballDirection)
    {
        this->ball.move(sf::Vector2f(this->ball.getMoveSpeed(), 0));
    }
    else
    {
        this->ball.move(sf::Vector2f(-this->ball.getMoveSpeed(), 0));
    }
}

// main update/render functions

void Game::update()
{
    /*
        Updates game objects before rendering them to the window.
    */
    this->pollEvents();

    this->movePaddle();

    this->moveBall();
}

void Game::render()
{
    /*
        Renders game objects to the window. Clears the window at the beginning and sets the background color to black.
    */
    this->window->clear(sf::Color::Black);

    // render game objects
    this->paddleLeft.draw(*this->window);
    this->paddleRight.draw(*this->window);
    this->ball.draw(*this->window);

    this->window->display();
}