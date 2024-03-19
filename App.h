#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "StateManager.h"

class App
{
private:
    // variables
    sf::RenderWindow *window;
    sf::VideoMode videoMode;
    sf::Event event;
    sf::Font font;
    StateManager stateManager;

public:
    // constructors/destructors/run
    App();
    virtual ~App();
    void run();

private:
    // private functions
    void initWindow();
    void initFont();
    void update();
    void render();
};