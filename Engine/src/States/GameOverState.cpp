#include "States/GameOverState.h"
#include "Util/ImageResourceManager.h"
#include <sstream>

GameOverState::GameOverState():GameState(NULL , STATE_GAMEOVER)
{
    //ctor
    m_playerScore = 0;
    m_victory = 0;
    m_backdrop = NULL;
    m_theme =NULL;
}

GameOverState::~GameOverState()
{
    if(m_backdrop)
    {
        delete m_backdrop;
    }
    if(m_theme)
    {
        delete m_theme;
        m_theme = NULL;
    }
}

void GameOverState::CheckEvent()
{
    while(m_engineInstance->GetGameWindow()->QueuedEvents())
    {
        // Get next event in event queue
        sf::Event* Event = m_engineInstance->GetGameWindow()->GetEvent();

        if(Event->type == sf::Event::Closed)
        {
            this->m_engineInstance->Running(false);
            EndState();
            m_engineInstance->GetGameWindow()->Close();
        }
        else if(Event->type == sf::Event::JoystickButtonPressed )
        {
            this->m_engineInstance->SwitchState(STATE_RANDOMREBOUND_GAMELEVEL);
        }
        else if(Event->type == sf::Event::KeyPressed)
        {
            switch(Event->key.code)
            {
            case sf::Keyboard::Key::Return:
            {
                this->m_engineInstance->SwitchState(STATE_RANDOMREBOUND_GAMELEVEL);
                break;
            }

            case sf::Keyboard::Key::Escape:
            {
                this->m_engineInstance->Running(false);
                EndState();
                m_engineInstance->GetGameWindow()->Close();
                break;
            }
            default:
                break;
            }
        }

    }

}

void GameOverState::UpdateLogic()
{
}

void GameOverState::Paint()const
{
    m_engineInstance->GetGameWindow()->Clear(sf::Color(0,0,0));
    m_backdrop->Draw(*m_engineInstance->GetGameWindow());
}

void GameOverState::InitState()
{
    ImageResourceManager::LoadImageResource("gameover_lose","img/gameover_lose.png");
    ImageResourceManager::LoadImageResource("gameover_win","img/gameover_win.png");

    m_backdrop = new GameSprite(Rect(0,0,640,480), Point(0,0), ImageResourceManager::GetImageResource("gameover_lose"));
}

void GameOverState::EndState()
{
    if(m_theme)
    {
        m_theme->stop();
    }
}

void GameOverState::StartState()
{
    m_engineInstance->GetGameWindow()->GetRawWindow()->setMouseCursorVisible(true);
    if(m_victory > 0)
    {
        m_backdrop->GetBaseSprite()->setTexture(ImageResourceManager::GetImageResource("gameover_win"));
    }
    else
    {
        m_backdrop->GetBaseSprite()->setTexture(ImageResourceManager::GetImageResource("gameover_lose"));
    }
}

void GameOverState::ExitState()
{
}

void GameOverState::PauseState()
{
}

void GameOverState::ResumeState()
{
}
void GameOverState::SetInt(const std::string& key, int value)
{
    // players final victor/loss message
    if(key == "Outcome")
    {
        m_victory = value;
    }

}
void GameOverState::SetFloat(const std::string& key, float value)
{
}
void GameOverState::SetString(const std::string& key, const std::string& value)
{
}
void GameOverState::SetObject(const std::string& key, void* value)
{
    if(key == "theme_music")
    {
        m_theme = (sf::Music*)value;
    }
}

