#include "Player.h"

// init methods

void Player::initVariables()
{
    /*
        Initializes the variables of the Player class.
    */
    this->score = 0;
}

void Player::initText(sf::Font &font)
{
    /*
        Initializes the text of the Player class.
    */
    this->text.setFont(font);
    this->text.setCharacterSize(75);
    this->text.setFillColor(sf::Color::White);
    this->text.setString("00");
    int textWidth = this->text.getGlobalBounds().width;
    if (this->isComputer)
    {
        this->text.setPosition(256 - textWidth / 2, 50);
    }
    else
    {
        this->text.setPosition(768 - textWidth / 2, 50);
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
    this->initText(font);
}

// other methods

void Player::appendScore()
{
    /*
        Appends the score of the player by 1.
    */
    this->score++;
}

void Player::updateText()
{
    /*
        Updates the text of the player to the current score.
    */
    std::stringstream scoreString;
    scoreString << std::setfill('0') << std::setw(2) << this->score;
    this->text.setString(scoreString.str());
}

void Player::renderScore(sf::RenderWindow *window)
{
    /*
        Renders the score of the player to the window.
    */
    window->draw(this->text);
}