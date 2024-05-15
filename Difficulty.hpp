#pragma once

#include <memory>

#include <SFML/Graphics/Text.hpp>

#include "State.hpp"
#include "Game.hpp"

class Difficulty : public Engine::State
{
private:
    std::shared_ptr<Context> m_context;
    //TITLE
    sf::Text m_DifficultyTitle;
    sf::Text m_easyModeText;
    sf::Text m_hardModeText;
    sf::Text m_mediumModeText;

    bool m_easyModeButtonSelected;
    bool m_easyModeButtonPressed;
    bool m_mediumModeButtonSelected;
    bool m_mediumModeButtonPressed;
    bool m_hardModeButtonSelected;
    bool m_hardModeButtonPressed;



public:
    Difficulty(std::shared_ptr<Context>& context);
    ~Difficulty();

    void Init() override;
    void ProcessInput() override;
    void Update(const sf::Time& deltaTime) override;
    void Draw() override;
};