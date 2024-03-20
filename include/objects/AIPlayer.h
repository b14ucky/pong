#pragma once

#include <SFML/Graphics.hpp>

#include "Player.h"
#include "AIPaddle.h"

class AIPlayer : public Player
{
private:
    int score;
    sf::Font font;
    sf::Text text;

public:
    // variables
    AIPaddle paddle;

    // constructors
    AIPlayer();
    AIPlayer(bool isComputer, sf::Font &font);
};