#include "HumanPlayer.h"

// constructors
HumanPlayer::HumanPlayer() {}

HumanPlayer::HumanPlayer(bool isComputer, sf::Font &font)
{
    this->isComputer = isComputer;
    this->initVariables();
    this->initText(font);
}