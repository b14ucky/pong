#pragma once

#include <SFML/Graphics.hpp>

#include <vector>

#include "State.h"
#include "StateManager.h"
#include "GameState.h"
#include "MenuStates.h"
#include "Difficulty.h"
#include "Button.h"

class MenuState : public State
{
private:
    // variables

    // text
    sf::Text title;
    sf::Text creditsText;
    sf::Text playText;

    // buttons
    std::vector<Button> mainMenuButtons;
    std::vector<Button> playButtons;
    std::vector<Button> creditsButtons;

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

    // init methods
    void initVariables();
    void initFont();
    void initText();
    void initButtons();

    // other private methods
    void setMenuState(MenuStates state);

    void updateMousePositions();
    void updateMainMenuButtons();
    void updatePlayButtons();
    void updateCreditsButtons();
    void renderMainMenuContent();
    void renderPlayContent();
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