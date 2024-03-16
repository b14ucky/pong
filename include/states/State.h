#pragma once

#include <SFML/Graphics.hpp>

class State
{
public:
    sf::RenderWindow *window;
    State();
    State(sf::RenderWindow *window);
    virtual void handleInput() = 0;
    virtual void update() = 0;
    virtual void render() = 0;
    // virtual void initWindow() = 0;
};