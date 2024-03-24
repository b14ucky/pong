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

    this->middleLine.setSize(sf::Vector2f(4, windowSizeY));
    this->middleLine.setFillColor(sf::Color::White);
    this->middleLine.setPosition(windowSizeX / 2 - this->middleLine.getSize().x / 2, 0);

    this->endGameTextBackground.setSize(sf::Vector2f(500, 400));
    this->endGameTextBackground.setFillColor(sf::Color::Black);
    this->endGameTextBackground.setOutlineThickness(2);
    this->endGameTextBackground.setOutlineColor(sf::Color::White);
    this->endGameTextBackground.setPosition(windowSizeX / 2 - this->endGameTextBackground.getSize().x / 2, windowSizeY / 2 - this->endGameTextBackground.getSize().y / 2);
}

void GameState::initButtons()
{
    /*
        Initializes the buttons of the Game class.
    */
    this->endGameButtons.push_back(Button("Play Again", this->font, 50, sf::Color::White, sf::Vector2f(this->window->getSize().x / 2, this->window->getSize().y / 2 + 25)));
    this->endGameButtons.push_back(Button("Main Menu", this->font, 50, sf::Color::White, sf::Vector2f(this->window->getSize().x / 2, this->window->getSize().y / 2 + 95)));
}

void GameState::initText()
{
    /*
        Initializes the text of the Game class.
    */
    this->endGameText.setFont(this->font);
    this->endGameText.setCharacterSize(50);
    this->endGameText.setFillColor(sf::Color::White);

    if (this->currentState == GameStates::PlayerLeftWon)
    {
        this->endGameText.setString("Player Left Won!");
    }
    else if (this->currentState == GameStates::PlayerRightWon)
    {
        this->endGameText.setString("Player Right Won!");
    }

    this->endGameText.setPosition(this->window->getSize().x / 2 - this->endGameText.getGlobalBounds().width / 2, 205);
}

// other private methods

void GameState::resetGame()
{
    /*
        Resets the game. Sets the ball and paddles to their initial positions.
    */
    this->stateManager->setState(std::make_unique<GameState>(this->window, this->stateManager, this->font, this->difficulty));
}

void GameState::updateGameOver()
{
    /*
        Updates the game over state. If the game is over, resets the game.
    */
    if (this->playerLeft.getScore() == 10)
    {
        this->currentState = GameStates::PlayerLeftWon;
        this->isGameOver = true;
    }
    if (this->playerRight.getScore() == 10)
    {
        this->currentState = GameStates::PlayerRightWon;
        this->isGameOver = true;
    }
}

void GameState::updateMousePositions()
{
    /*
        Update the mouse positions
    */
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(mousePosWindow);
}

void GameState::updateGameOverMenu()
{
    /*
        Updates the game over menu.
    */
    for (auto &button : this->endGameButtons)
    {
        if (button.getGlobalBounds().contains(this->mousePosView))
        {
            button.setScale(1.115f, 1.115f);
        }
        else
        {
            button.setScale(1.0f, 1.0f);
        }
    }
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
    this->isGameOver = false;
    this->currentState = GameStates::Playing;
    this->mouseHeld = false;
    this->initPlayers();
    this->initGameObjects();
    this->initButtons();
}

GameState::~GameState()
{
    /*
        The destructor of the Game class.
    */
}

// other public methods

void GameState::handleInput()
{
    /*
        Moves the paddles up or down depending on the key pressed.
    */
    if (!this->isGameOver)
    {
        this->playerLeft.paddle.handleMovement(this->window->getSize(), this->ball.getPosition());
        this->playerRight.paddle.handleMovement(this->window->getSize(), this->ball.getPosition());
    }
    else
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (!this->mouseHeld)
            {
                this->mouseHeld = true;
                if (this->endGameButtons[0].getGlobalBounds().contains(this->mousePosView))
                {
                    this->resetGame();
                }
                else if (this->endGameButtons[1].getGlobalBounds().contains(this->mousePosView))
                {
                    this->stateManager->setState(std::make_unique<MenuState>(this->window, this->stateManager, this->font));
                }
            }
        }
        else
        {
            this->mouseHeld = false;
        }
    }
}

// main update/render functions

void GameState::update()
{
    /*
        Updates game objects before rendering them to the window.
    */
    if (!this->isGameOver)
    {
        this->updateGameOver();
        this->ball.handleMovement();
        this->ball.handleCollisions(this->playerLeft, this->playerRight, this->window);
        this->playerLeft.updateText();
        this->playerRight.updateText();
    }
    else
    {
        this->initText();
        this->updateMousePositions();
        this->updateGameOverMenu();
    }

    this->handleInput();
}

void GameState::render()
{
    /*
        Renders game objects to the window. Clears the window at the beginning and sets the background color to black.
    */
    this->window->draw(this->middleLine);
    this->playerLeft.paddle.draw(*this->window);
    this->playerRight.paddle.draw(*this->window);
    this->ball.draw(*this->window);
    this->playerLeft.renderScore(this->window);
    this->playerRight.renderScore(this->window);

    if (this->isGameOver)
    {
        this->window->draw(this->endGameTextBackground);
        this->window->draw(this->endGameText);
        for (auto &button : this->endGameButtons)
        {
            this->window->draw(button);
        }
    }
}