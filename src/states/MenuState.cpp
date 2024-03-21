#include "MenuState.h"

// init methods
void MenuState::initVariables()
{
    this->mouseHeld = false;
    this->scale.x = 1.115f;
    this->scale.y = 1.115f;
    this->currentState = MenuStates::MainMenu;
    this->previousState = MenuStates::MainMenu;
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
}

void MenuState::initButtons()
{
    this->play = Button("PLAY", this->font, 85, sf::Color::White, sf::Vector2f(this->window->getSize().x / 2, 255));
    buttons.push_back(this->play);

    this->options = Button("OPTIONS", this->font, 85, sf::Color::White, sf::Vector2f(this->window->getSize().x / 2, 330));
    buttons.push_back(this->options);

    this->credits = Button("CREDITS", this->font, 85, sf::Color::White, sf::Vector2f(this->window->getSize().x / 2, 405));
    buttons.push_back(this->credits);

    this->exit = Button("EXIT", this->font, 75, sf::Color::White, sf::Vector2f(this->window->getSize().x / 2, this->window->getSize().y - 100));
    buttons.push_back(this->exit);

    this->goBack = Button("GO BACK", this->font, 75, sf::Color::White, sf::Vector2f(this->window->getSize().x / 2, this->window->getSize().y - 100));
    buttons.push_back(this->goBack);
}

// other private methods

void MenuState::setMenuState(MenuStates state)
{
    this->previousState = this->currentState;
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

void MenuState::updateButtons()
{
    /*
        This function updates the buttons in the MenuState.
        It changes the scale of the buttons when the mouse hovers over them.
    */
    for (auto &button : buttons)
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
        This function renders the text objects in the MenuState.
    */
    this->window->draw(title);

    for (auto &button : buttons)
    {
        if (button.getString() != "GO BACK")
        {
            this->window->draw(button);
        }
    }
}

void MenuState::renderCreditsContent()
{
    /*
        This function renders the credits text.
    */
    for (auto &button : buttons)
    {
        if (button.getString() == "GO BACK")
        {
            this->window->draw(button);
        }
    }
    this->window->draw(creditsText);
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
    this->updateButtons();
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
                if (this->play.getGlobalBounds().contains(this->mousePosView))
                {
                    this->stateManager->setState(std::make_unique<GameState>(this->window, this->stateManager, this->font));
                }
                if (this->credits.getGlobalBounds().contains(this->mousePosView))
                {
                    this->setMenuState(MenuStates::Credits);
                }
                if (this->exit.getGlobalBounds().contains(this->mousePosView))
                {
                    this->window->close();
                }
                break;
            }
            case MenuStates::Credits:
            case MenuStates::Options:
            {
                if (this->goBack.getGlobalBounds().contains(this->mousePosView))
                {
                    this->setMenuState(this->previousState);
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