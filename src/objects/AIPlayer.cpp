#include "AIPlayer.h"

// constructor

AIPlayer::AIPlayer() {}

AIPlayer::AIPlayer(bool isComputer, sf::Font &font)
{
    this->isComputer = isComputer;
    this->initVariables();
    this->initFont();
    this->initText(font);
}