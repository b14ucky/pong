#include "MenuState.h"

// init methods
void MenuState::initVariables()
{
    this->mouseHeld = false;
    this->scale.x = 1.115f;
    this->scale.y = 1.115f;
    this->currentState = MenuStates::MainMenu;
}

void MenuState::initFont()
{
    /*
        This function loads the font and sets it to the text objects
    */
    if (!this->font.loadFromFile("./assets/fonts/Imagine_Font.ttf"))
    {
        std::cout << "ERROR::MENUSTATE::INITFONTS::Failed to load font" << std::endl;
    }

    this->title.setFont(this->font);
    this->creditsText.setFont(this->font);
    this->playText.setFont(this->font);
}

void MenuState::initText()
{
    this->title.setString("PONG");
    this->title.setCharacterSize(250);
    this->title.setFillColor(sf::Color::White);
    this->title.setOrigin(this->title.getGlobalBounds().getSize().x / 2, this->title.getGlobalBounds().getSize().y / 2);
    this->title.setPosition(this->window->getSize().x / 2, 25);

    this->creditsText.setString("This game was created by:\n\n"
                                "Dominik Meisner\n");
    this->creditsText.setCharacterSize(50);
    this->creditsText.setFillColor(sf::Color::White);
    this->creditsText.setOrigin(creditsText.getGlobalBounds().getSize().x / 2, creditsText.getGlobalBounds().getSize().y / 2);
    this->creditsText.setPosition(this->window->getSize().x / 2, this->window->getSize().y / 2);

    this->playText.setString("Game difficulty");
    this->playText.setCharacterSize(100);
    this->playText.setFillColor(sf::Color::White);
    this->playText.setOrigin(playText.getGlobalBounds().getSize().x / 2, playText.getGlobalBounds().getSize().y / 2);
    this->playText.setPosition(this->window->getSize().x / 2, 100);
}

void MenuState::initButtons()
{
    /*
        This function initializes the buttons in the MenuState.
        It sets the text, font, size, color and position of the buttons.
        It also adds the buttons to the corresponding vectors.
    */
    this->mainMenuButtons.push_back(Button("PLAY", this->font, 85, sf::Color::White, sf::Vector2f(this->window->getSize().x / 2, 270)));
    this->mainMenuButtons.push_back(Button("OPTIONS", this->font, 85, sf::Color::White, sf::Vector2f(this->window->getSize().x / 2, 345)));
    this->mainMenuButtons.push_back(Button("CREDITS", this->font, 85, sf::Color::White, sf::Vector2f(this->window->getSize().x / 2, 420)));
    this->mainMenuButtons.push_back(Button("EXIT", this->font, 75, sf::Color::White, sf::Vector2f(this->window->getSize().x / 2, this->window->getSize().y - 100)));

    this->playButtons.push_back(Button("EASY", this->font, 75, sf::Color::White, sf::Vector2f(this->window->getSize().x / 2, 270)));
    this->playButtons.push_back(Button("MEDIUM", this->font, 75, sf::Color::White, sf::Vector2f(this->window->getSize().x / 2, 345)));
    this->playButtons.push_back(Button("HARD", this->font, 75, sf::Color::White, sf::Vector2f(this->window->getSize().x / 2, 420)));
    this->playButtons.push_back(Button("IMPOSSIBLE", this->font, 75, sf::Color::White, sf::Vector2f(this->window->getSize().x / 2, 495)));
    this->playButtons.push_back(Button("GO BACK", this->font, 75, sf::Color::White, sf::Vector2f(this->window->getSize().x / 2, this->window->getSize().y - 100)));

    this->creditsButtons.push_back(Button("GO BACK", this->font, 75, sf::Color::White, sf::Vector2f(this->window->getSize().x / 2, this->window->getSize().y - 100)));
}

// other private methods

void MenuState::setMenuState(MenuStates state)
{
    this->currentState = state;
}

void MenuState::updateMousePositions()
{
    /*
        Update the mouse positions
    */
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(mousePosWindow);
}

void MenuState::updateMainMenuButtons()
{
    /*
        This function updates the buttons in the main menu.
        It changes the scale of the buttons when the mouse hovers over them.
    */
    for (auto &button : mainMenuButtons)
    {
        if (button.getGlobalBounds().contains(this->mousePosView))
        {
            button.setScale(this->scale);
        }
        else
        {
            button.setScale(1.0f, 1.0f);
        }
    }
}

void MenuState::updatePlayButtons()
{
    /*
        This function updates the buttons in the play menu.
        It changes the scale of the buttons when the mouse hovers over them.
    */
    for (auto &button : playButtons)
    {
        if (button.getGlobalBounds().contains(this->mousePosView))
        {
            button.setScale(this->scale);
        }
        else
        {
            button.setScale(1.0f, 1.0f);
        }
    }
}

void MenuState::updateCreditsButtons()
{
    /*
        This function updates the buttons in the credits menu.
        It changes the scale of the buttons when the mouse hovers over them.
    */
    for (auto &button : creditsButtons)
    {
        if (button.getGlobalBounds().contains(this->mousePosView))
        {
            button.setScale(this->scale);
        }
        else
        {
            button.setScale(1.0f, 1.0f);
        }
    }
}

void MenuState::renderMainMenuContent()
{
    /*
        This function renders the contents of the main menu.
    */
    this->window->draw(title);

    for (auto &button : mainMenuButtons)
    {
        this->window->draw(button);
    }
}

void MenuState::renderPlayContent()
{
    /*
        This function renders the contents of the play menu.
    */
    this->window->draw(playText);

    for (auto &button : playButtons)
    {
        this->window->draw(button);
    }
}

void MenuState::renderCreditsContent()
{
    /*
        This function renders the contents of the credits menu.
    */
    this->window->draw(creditsText);

    for (auto &button : creditsButtons)
    {
        this->window->draw(button);
    }
}

// constructors/destructors
MenuState::MenuState(sf::RenderWindow *window, StateManager *stateManager, sf::Font &font)
{
    this->window = window;
    this->stateManager = stateManager;
    this->font = font;
    this->initVariables();
    this->initFont();
    this->initText();
    this->initButtons();
}

MenuState::~MenuState()
{
    /*
        Destructor for the MenuState class
    */
}

// main update/render methods

void MenuState::update()
{
    /*
        This function updates the MenuState.
    */
    this->updateMousePositions();
    switch (this->currentState)
    {
    case MenuStates::MainMenu:
        this->updateMainMenuButtons();
        break;
    case MenuStates::Play:
        this->updatePlayButtons();
        break;
    case MenuStates::Credits:
        this->updateCreditsButtons();
        break;
    default:
        break;
    }
}

void MenuState::render()
{
    /*
        This function renders the MenuState's elements.
    */
    switch (this->currentState)
    {
    case MenuStates::MainMenu:
        this->renderMainMenuContent();
        break;
    case MenuStates::Play:
        this->renderPlayContent();
        break;
    case MenuStates::Credits:
        this->renderCreditsContent();
        break;
    default:
        break;
    }
}

// other methods
void MenuState::handleInput()
{
    /*
        This function handles mouse input for the MenuState.
        It changes the state to GameState when the play button is clicked.
        It closes the window when the exit button is clicked.
    */
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        if (!this->mouseHeld)
        {
            this->mouseHeld = true;
            switch (this->currentState)
            {
            case MenuStates::MainMenu:
            {
                if (this->mainMenuButtons[0].getGlobalBounds().contains(this->mousePosView))
                {
                    this->setMenuState(MenuStates::Play);
                }
                if (this->mainMenuButtons[2].getGlobalBounds().contains(this->mousePosView))
                {
                    this->setMenuState(MenuStates::Credits);
                }
                if (this->mainMenuButtons[3].getGlobalBounds().contains(this->mousePosView))
                {
                    this->window->close();
                }
                break;
            }
            case MenuStates::Play:
            {
                if (this->playButtons[0].getGlobalBounds().contains(this->mousePosView))
                {
                    this->stateManager->setState(std::make_unique<GameState>(this->window, this->stateManager, this->font, Difficulty::Easy));
                }
                if (this->playButtons[1].getGlobalBounds().contains(this->mousePosView))
                {
                    this->stateManager->setState(std::make_unique<GameState>(this->window, this->stateManager, this->font, Difficulty::Medium));
                }
                if (this->playButtons[2].getGlobalBounds().contains(this->mousePosView))
                {
                    this->stateManager->setState(std::make_unique<GameState>(this->window, this->stateManager, this->font, Difficulty::Hard));
                }
                if (this->playButtons[3].getGlobalBounds().contains(this->mousePosView))
                {
                    this->stateManager->setState(std::make_unique<GameState>(this->window, this->stateManager, this->font, Difficulty::Impossible));
                }
                if (this->playButtons[4].getGlobalBounds().contains(this->mousePosView))
                {
                    this->setMenuState(MenuStates::MainMenu);
                }
            }
            case MenuStates::Credits:
            {
                if (this->creditsButtons[0].getGlobalBounds().contains(this->mousePosView))
                {
                    this->setMenuState(MenuStates::MainMenu);
                }
                break;
            }
            }
        }
    }
    else
    {
        this->mouseHeld = false;
    }
}