#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>

#include "State.h"
#include "Ball.h"
#include "HumanPlayer.h"

class GameState : public State
{
private:
    // game objects
    Ball ball;
    HumanPlayer playerLeft;
    HumanPlayer playerRight;

    // window
    sf::RenderWindow *window;
    sf::Font font;

public:
    // constructors/destructors
    GameState(sf::RenderWindow *window, sf::Font &font);
    virtual ~GameState();

    // init methods
    void initGameObjects();
    void initPlayers();

    // main update/render methods
    void update() override;
    void render() override;

    // other methods
    void handleInput() override;
};
