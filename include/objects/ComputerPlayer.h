#pragma once

#include <SFML/Graphics.hpp>

#include "Player.h"
#include "ComputerPaddle.h"
#include "Difficulty.h"

class ComputerPlayer : public Player
{
private:
    int score;
    sf::Font font;
    sf::Text text;

public:
    // variables
    ComputerPaddle paddle;

    // constructors
    ComputerPlayer();
    ComputerPlayer(bool isComputer, sf::Font &font, Difficulty difficulty);
};