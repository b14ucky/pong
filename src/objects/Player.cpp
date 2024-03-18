#include "Player.h"

// init methods

void Player::initVariables()
{
    /*
        Initializes the variables of the Player class.
    */
    this->score = 0;
}

void Player::initFont()
{
    /*
        Initializes the font of the Player class.
    */
    if (!this->font.loadFromFile("C:/Windows/Fonts/arial.ttf"))
    {
        std::cout << "Error: Player::initFont: Could not load font from file." << std::endl;
    }
}

void Player::initText(sf::Font &font)
{
    /*
        Initializes the text of the Player class.
    */
    this->text.setFont(font);
    this->text.setCharacterSize(50);
    this->text.setFillColor(sf::Color::White);
    this->text.setString(std::to_string(this->score));
    if (this->isComputer)
    {
        this->text.setPosition(256, 50);
    }
    else
    {
        this->text.setPosition(768, 50);
    }
}

// constructors/destructors

Player::Player()
{
    /*
        The default constructor of the Player class. Calls all the init methods to initialize the player.
    */
}

Player::Player(bool isComputer, sf::Font &font)
{
    /*
        The constructor of the Player class. Calls all the init methods to initialize the player.
    */
    this->isComputer = isComputer;
    this->initVariables();
    this->initFont();
    this->initText(font);
}

// other methods

void Player::appendScore()
{
    /*
        Appends the score of the player by 1.
    */
    this->score++;
    this->text.setString(std::to_string(this->score));
}

void Player::renderScore(sf::RenderWindow *window)
{
    /*
        Renders the score of the player to the window.
    */
    window->draw(this->text);
}