#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>

#include "StateManager.h"
#include "State.h"
#include "Ball.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "Difficulty.h"

class GameState : public State
{
private:
    // game objects
    Ball ball;
    HumanPlayer playerLeft;
    ComputerPlayer playerRight;

    // window
    sf::RenderWindow *window;
    sf::Font font;

    // init methods
    void initGameObjects();
    void initPlayers();

    StateManager *stateManager;
    Difficulty difficulty;

public:
    // constructors/destructors
    GameState(sf::RenderWindow *window, StateManager *stateManager, sf::Font &font, Difficulty difficulty);
    virtual ~GameState();

    // main update/render methods
    void update() override;
    void render() override;

    // other methods
    void handleInput() override;
};
