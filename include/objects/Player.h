#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>

#include "Paddle.h"

class Player
{
private:
    int score;
    sf::Font font;
    sf::Text text;

public:
    bool isComputer;
    Paddle paddle;
    // constructors/destructors
    Player();
    Player(bool isComputer, sf::Font &font);

    // other methods
    void appendScore();
    void renderScore(sf::RenderWindow *window);

    // init methods
    void initVariables();
    void initFont();
    void initText(sf::Font &font);
};