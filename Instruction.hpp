#pragma once

#include <memory>

#include <SFML/Graphics/Text.hpp>

#include "State.hpp"
#include "Game.hpp"

class Instruction : public Engine::State
{
private:
    std::shared_ptr<Context> m_context;
    //TITLE
    sf::Text m_InstructionTilte;
    sf::Text m_InstructionText;
    sf::Text m_backToMenuText;
    
    bool m_BackToMenuSelected; 
    


public:
    Instruction(std::shared_ptr<Context>& context);
    ~Instruction();

    void Init() override;
    void ProcessInput() override;
    void Update(const sf::Time& deltaTime) override;
    void Draw() override;
};