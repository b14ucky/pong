#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>

#include "StateManager.h"
#include "State.h"
#include "Ball.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "Difficulty.h"
#include "Button.h"
#include "GameStates.h"
#include "MenuState.h"

class GameState : public State
{
private:
    // game objects
    Ball ball;
    sf::RectangleShape middleLine;
    sf::RectangleShape endGameTextBackground;

    // players
    HumanPlayer playerLeft;
    ComputerPlayer playerRight;

    // text
    sf::Text endGameText;

    // buttons
    std::vector<Button> endGameButtons;

    // window
    sf::RenderWindow *window;
    sf::Font font;

    // mouse
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    // init methods
    void initGameObjects();
    void initPlayers();
    void initButtons();
    void initText();

    StateManager *stateManager;
    Difficulty difficulty;

    // variables
    bool isGameOver;
    bool mouseHeld;
    GameStates currentState;

    // other private methods
    void resetGame();
    void updateGameOver();
    void updateMousePositions();
    void updateGameOverMenu();

public:
    // constructors/destructors
    GameState(sf::RenderWindow *window, StateManager *stateManager, sf::Font &font, Difficulty difficulty);
    virtual ~GameState();

    // main update/render methods
    void update() override;
    void render() override;

    // other public methods
    void handleInput() override;
};
