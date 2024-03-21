#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

#include "Paddle.h"

class Player
{
protected:
    int score;
    sf::Text text;

public:
    bool isComputer;

    // constructors/destructors
    Player();
    Player(bool isComputer, sf::Font &font);

    // other methods
    void appendScore();
    void updateText();
    void renderScore(sf::RenderWindow *window);

    // init methods
    void initVariables();
    void initText(sf::Font &font);
};