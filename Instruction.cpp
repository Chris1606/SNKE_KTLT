#include "Instruction.hpp"
#include "SFML/Window/Event.hpp"
#include "GamePlay.hpp"
#include "MainMenu.hpp"
#include "Instruction.hpp"
Instruction::Instruction(std::shared_ptr<Context>& context)
    :m_context(context), m_BackToMenuSelected(false)
{
}
Instruction::~Instruction() {

}

void Instruction::Init()
{
    m_context->m_assets->AddFont(MAIN_FONT, "D:/2D-Snake-Game/assets/fonts/Pacifico-Regular.ttf");

    //Title 
    m_InstructionTilte.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_InstructionTilte.setFillColor(sf::Color::Yellow);
    m_InstructionTilte.setString("Instruction");
    //set the Tile to the center
    m_InstructionTilte.setOrigin(m_InstructionTilte.getLocalBounds().width / 2,
        m_InstructionTilte.getLocalBounds().height / 2);
    m_InstructionTilte.setPosition(m_context->m_window->getSize().x / 2,
        m_context->m_window->getSize().y / 2 - 100.f);

    //Instruction 
    m_InstructionText.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_InstructionText.setString("         Use WASD to move Snake.\n If snake hit the wall or body, You will lose.");
    m_InstructionText.setOrigin(m_InstructionText.getLocalBounds().width / 2,
        m_InstructionText.getLocalBounds().height / 2);
    m_InstructionText.setPosition(m_context->m_window->getSize().x / 2 + 120.f,
        m_context->m_window->getSize().y / 2 - 10.f);
    m_InstructionText.setCharacterSize(20);

    //Back to menu
    m_backToMenuText.setFont(m_context->m_assets->GetFont(MAIN_FONT));
    m_backToMenuText.setString("Pressed any keys to back");
    m_backToMenuText.setOrigin(m_backToMenuText.getLocalBounds().width / 2,
        m_backToMenuText.getLocalBounds().height / 2);
    m_backToMenuText.setPosition(m_context->m_window->getSize().x / 2 + 120.f,
        m_context->m_window->getSize().y / 2 + 20.f);
    m_backToMenuText.setCharacterSize(20);



}

void Instruction::ProcessInput()
{
    sf::Event event;
    while (m_context->m_window->pollEvent(event))
    {
        //check close event
        if (event.type == sf::Event::Closed) {

            m_context->m_window->close();
        }
        else if (event.type == sf::Event::KeyPressed) {
            m_BackToMenuSelected = true;
        }
    }
}

void Instruction::Update(const sf::Time& deltaTime)
{
    if (m_BackToMenuSelected == true) 
        m_context->m_states->Add(std::make_unique<MainMenu>(m_context), true);
   
}

void Instruction::Draw()
{
    m_context->m_window->clear(sf::Color::Red);
    m_context->m_window->draw(m_InstructionTilte);
    m_context->m_window->draw(m_InstructionText);
    m_context->m_window->display();
}