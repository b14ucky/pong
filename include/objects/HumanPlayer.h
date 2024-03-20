#pragma once

#include <SFML/Graphics.hpp>

#include "Player.h"
#include "UserPaddle.h"

class HumanPlayer : public Player
{
private:
    int score;
    sf::Font font;
    sf::Text text;

public:
    // variables
    UserPaddle paddle;

    // constructors
    HumanPlayer();
    HumanPlayer(bool isComputer, sf::Font &font);
};