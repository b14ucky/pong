#include "ComputerPlayer.h"

// constructor

ComputerPlayer::ComputerPlayer() {}

ComputerPlayer::ComputerPlayer(bool isComputer, sf::Font &font, Difficulty difficulty)
{
    this->paddle = ComputerPaddle(difficulty);
    this->isComputer = isComputer;
    this->initVariables();
    this->initText(font);
}