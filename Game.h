#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include <iostream>

#include "Paddle.h"
#include "Ball.h"

class Game
{
private:
    // variables
    sf::RenderWindow *window;
    sf::VideoMode videoMode;
    sf::Event event;

    // game objects
    Paddle paddleLeft;
    Paddle paddleRight;
    Ball ball;

    // game logic
    bool ballDirection; // false - left, true - right

public:
    // constructors/destructors
    Game();
    virtual ~Game();

    // accessors
    const bool running() const;

    // init functions
    void initWindow();
    void initVariables();
    void initGameObjects();

    // main update/render functions
    void update();
    void render();

    // other functions
    void pollEvents();
    void movePaddle();
    void moveBall();
};
