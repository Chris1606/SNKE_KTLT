#include "Difficulty.hpp"
#include "SFML/Window/Event.hpp"
#include "GamePlay.hpp"
#include "MainMenu.hpp"
#include "Difficulty.hpp"
#include "easyGamePlay.hpp"
#include "mediumGamePlay.hpp"
#include "hardGamePlay.hpp"

Difficulty::Difficulty(std::shared_ptr<Context>& context)
    :m_context(context), m_easyModeButtonSelected(true), m_easyModeButtonPressed(false), 
    m_mediumModeButtonSelected(false), m_mediumModeButtonPressed(false), m_hardModeButtonSelected(false), m_hardModeButtonPressed(false)
{
}
Difficulty::~Difficulty() {

}

void Difficulty::Init()
{
    m_context->m_assets->AddFont(MAIN_FONT, "D:/2D-Snake-Game/assets/fonts/Pacifico-Regular.ttf");

    //Title 
    m_DifficultyTitle.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_DifficultyTitle.setFillColor(sf::Color::Yellow);
    m_DifficultyTitle.setString("Difficulty");
    //set the Tile to the center
    m_DifficultyTitle.setOrigin(m_DifficultyTitle.getLocalBounds().width / 2,
        m_DifficultyTitle.getLocalBounds().height / 2);
    m_DifficultyTitle.setPosition(m_context->m_window->getSize().x / 2,
        m_context->m_window->getSize().y / 2 - 100.f);

    //Difficulty 

    //Easy
    m_easyModeText.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_easyModeText.setString("Easy");
    m_easyModeText.setOrigin(m_easyModeText.getLocalBounds().width / 2,
        m_easyModeText.getLocalBounds().height / 2);
    m_easyModeText.setPosition(m_context->m_window->getSize().x / 2,
        m_context->m_window->getSize().y / 2 - 50.f);
    m_easyModeText.setCharacterSize(20);

    //Medium
    m_mediumModeText.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_mediumModeText.setString("Medium");
    m_mediumModeText.setOrigin(m_mediumModeText.getLocalBounds().width / 2 - 15.f,
        m_mediumModeText.getLocalBounds().height / 2);
    m_mediumModeText.setPosition(m_context->m_window->getSize().x / 2,
        m_context->m_window->getSize().y / 2 );
    m_mediumModeText.setCharacterSize(20);

    //Hard
    m_hardModeText.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_hardModeText.setString("Hard");
    m_hardModeText.setOrigin(m_hardModeText.getLocalBounds().width / 2,
        m_hardModeText.getLocalBounds().height / 2);
    m_hardModeText.setPosition(m_context->m_window->getSize().x / 2,
        m_context->m_window->getSize().y / 2 + 50.f );
    m_hardModeText.setCharacterSize(20);


}
void Difficulty::ProcessInput()
{
    sf::Event event;
    while (m_context->m_window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed) {
            m_context->m_window->close();
        }
        else if (event.type == sf::Event::KeyPressed) {
            switch (event.key.code) {
            case sf::Keyboard::Up:
                if (m_mediumModeButtonSelected) {
                    m_mediumModeButtonSelected = false;
                    m_easyModeButtonSelected = true;
                }
                else if (m_hardModeButtonSelected) {
                    m_hardModeButtonSelected = false;
                    m_mediumModeButtonSelected = true;
                }
                break;
            case sf::Keyboard::Down:
                if (m_easyModeButtonSelected) {
                    m_easyModeButtonSelected = false;
                    m_mediumModeButtonSelected = true;
                }
                else if (m_mediumModeButtonSelected) {
                    m_mediumModeButtonSelected = false;
                    m_hardModeButtonSelected = true;
                }
                break;
            case sf::Keyboard::Return:
                if (m_easyModeButtonSelected) {
                    // Set difficulty to easy and start game
                    m_context->m_states->Add(std::make_unique<easyGamePlay>(m_context), true);
                }
                else if (m_mediumModeButtonSelected) {
                    // Set difficulty to medium and start game
                    m_context->m_states->Add(std::make_unique<mediumGamePlay
                    >(m_context), true);
                }
                else if (m_hardModeButtonSelected) {
                    // Set difficulty to hard and start game

                    m_context->m_states->Add(std::make_unique<hardGamePlay>(m_context), true);
                }
                break;
            default:
                break;
            }
        }
    }
}

void Difficulty::Update(const sf::Time& deltaTime)
{
    // Reset fill colors
    m_easyModeText.setFillColor(sf::Color::White);
    m_mediumModeText.setFillColor(sf::Color::White);
    m_hardModeText.setFillColor(sf::Color::White);

    // Highlight selected button
    if (m_easyModeButtonSelected)
        m_easyModeText.setFillColor(sf::Color::Blue);
    if (m_mediumModeButtonSelected)
        m_mediumModeText.setFillColor(sf::Color::Blue);
    if (m_hardModeButtonSelected)
        m_hardModeText.setFillColor(sf::Color::Blue);
}

void Difficulty::Draw()
{
    m_context->m_window->clear(sf::Color::Red);
    m_context->m_window->draw(m_DifficultyTitle);
    m_context->m_window->draw(m_easyModeText);
    m_context->m_window->draw(m_mediumModeText);
    m_context->m_window->draw(m_hardModeText);
    m_context->m_window->display();
}
