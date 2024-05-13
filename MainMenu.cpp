#include "MainMenu.hpp"
#include "GamePlay.hpp"
#include <SFML/Window/Event.hpp>

MainMenu::MainMenu(std::shared_ptr<Context>& context)
    :m_context(context), m_isPlayButtonSelected(true), m_isPlayButtonPressed(false),
    m_isExitButtonSelected(false), m_isExitButtonPressed(false)
{
}

MainMenu::~MainMenu()
{   
}

void MainMenu::Init()
{
    m_context->m_assets->AddFont(MAIN_FONT, "D:/2D-Snake-Game/assets/fonts/Pacifico-Regular.ttf");

    //Title button
    m_gameTitle.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_gameTitle.setFillColor(sf::Color::Yellow);
    m_gameTitle.setString("Snake Game");
    //set the Tile to the center
    m_gameTitle.setOrigin(m_gameTitle.getLocalBounds().width / 2,   
                          m_gameTitle.getLocalBounds().height / 2);
    m_gameTitle.setPosition(m_context->m_window->getSize().x / 2, 
                            m_context->m_window->getSize().y / 2 - 100.f);

    //Play
    m_playButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_playButton.setString("Play");
    m_playButton.setOrigin(m_playButton.getLocalBounds().width / 2,
                        m_playButton.getLocalBounds().height / 2);
    m_playButton.setPosition(m_context->m_window->getSize().x / 2,
                            m_context->m_window->getSize().y / 2 - 25.f);
    m_playButton.setCharacterSize(20);
    
    //Exit
    m_exitButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_exitButton.setString("Exit");
    m_exitButton.setOrigin(m_exitButton.getLocalBounds().width / 2,
                           m_exitButton.getLocalBounds().height / 2);
    m_exitButton.setPosition(m_context->m_window->getSize().x / 2,
                            m_context->m_window->getSize().y / 2 + 25.f);
    m_exitButton.setCharacterSize(20);

}

void MainMenu::ProcessInput()
{
    sf::Event event;
    while (m_context->m_window->pollEvent(event))
    {
        //check close event
        if (event.type == sf::Event::Closed) {

            m_context->m_window->close();
        }
        else if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) // store the key that pressed
            {
            case sf::Keyboard::Up: {
                if (!m_isPlayButtonSelected) { //keep looping between 2 option 
                    m_isPlayButtonSelected = true;
                    m_isExitButtonSelected = false;
                }
                break;
            }            
            case sf::Keyboard::Down: {
                if (!m_isExitButtonSelected) { //keep looping between 2 option 
                    m_isPlayButtonSelected = false;
                    m_isExitButtonSelected = true;
                }
                break;
            }
            case sf::Keyboard::Return: {
                //enter selection to choose
                m_isPlayButtonPressed = false;
                m_isExitButtonPressed = false;
                if (m_isPlayButtonSelected) {
                    m_isPlayButtonPressed = true;
                }
                else {
                    m_isExitButtonPressed = true;
                }
                break;
            }
                default:
                    break;
            }
        }
    }
}

void MainMenu::Update(const sf::Time& deltaTime)
{
    if (m_isPlayButtonSelected) {
        m_playButton.setFillColor(sf::Color::Blue);
        m_exitButton.setFillColor(sf::Color::White);
    }
    else {
        m_playButton.setFillColor(sf::Color::White);
        m_exitButton.setFillColor(sf::Color::Blue);
    }
    if (m_isPlayButtonPressed) {
        //go to play state
       /* m_playButton.setColor(sf::Color::Magenta);*/

        m_context->m_states->Add(std::make_unique<GamePlay>(m_context), true);
    }
    else if(m_isExitButtonPressed) {
       /* m_exitButton.setColor(sf::Color::Magenta);*/
        m_context->m_window->close();
    }
}

void MainMenu::Draw()
{
    m_context->m_window->clear(sf::Color::Red);
    m_context->m_window->draw(m_gameTitle);
    m_context->m_window->draw(m_playButton);
    m_context->m_window->draw(m_exitButton);
    m_context->m_window->display();
}