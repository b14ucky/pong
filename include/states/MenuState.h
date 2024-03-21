#pragma once

#include <SFML/Graphics.hpp>

#include <vector>

#include "State.h"
#include "StateManager.h"
#include "GameState.h"
#include "MenuStates.h"
#include "Button.h"

class MenuState : public State
{
private:
    // variables

    // text
    sf::Text title;
    sf::Text creditsText;

    // buttons
    std::vector<Button> buttons;
    Button play;
    Button options;
    Button credits;
    Button exit;
    Button goBack;

    sf::Vector2f scale;

    // font
    sf::Font font;

    // mouse variables
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;
    bool mouseHeld;

    // window
    sf::RenderWindow *window;
    StateManager *stateManager;

    // menu state
    MenuStates currentState;
    MenuStates previousState;

    // init methods
    void initVariables();
    void initFont();
    void initText();
    void initButtons();

    // other private methods
    void setMenuState(MenuStates state);

    void updateMousePositions();
    void updateButtons();
    void renderMainMenuContent();
    void renderCreditsContent();

public:
    // constructors/destructors
    MenuState(sf::RenderWindow *window, StateManager *stateManager, sf::Font &font);
    virtual ~MenuState();

    // main update/render methods
    void update() override;
    void render() override;

    // other methods
    void handleInput() override;
};