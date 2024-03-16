#pragma once

#include <SFML/Graphics.hpp>

#include <iostream>

#include "State.h"
#include "Paddle.h"
#include "Ball.h"

class GameState : public State
{
private:
    // game objects
    Paddle paddleLeft;
    Paddle paddleRight;
    Ball ball;

    // window
    sf::RenderWindow *window;

public:
    // constructors/destructors
    GameState(sf::RenderWindow *window);
    virtual ~GameState();

    // init functions
    // void initVariables();
    void initGameObjects();

    // main update/render functions
    void update() override;
    void render() override;

    // other functions
    void handleInput() override;
};
