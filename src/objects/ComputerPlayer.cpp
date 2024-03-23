#include "ComputerPlayer.h"

// constructor

ComputerPlayer::ComputerPlayer() {}

ComputerPlayer::ComputerPlayer(bool isComputer, sf::Font &font)
{
    this->isComputer = isComputer;
    this->initVariables();
    this->initText(font);
}