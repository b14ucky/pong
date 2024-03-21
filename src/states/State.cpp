#include "State.h"

State::State() {}

State::State(sf::RenderWindow *window, StateManager *stageManager)
{
    this->window = window;
    this->stateManager = stageManager;
}