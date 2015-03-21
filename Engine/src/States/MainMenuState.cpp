#include "States/MainMenuState.h"
#include "Util/ImageResourceManager.h"
#include "Util/Point.h"
#include "Util/Rect.h"

MainMenuState::MainMenuState():GameState(NULL , STATE_MAINMENU)
{
    m_titlescreen = NULL;
    m_theme = NULL;
}

MainMenuState::~MainMenuState()
{
    //dtor
    if(m_titlescreen)
    {
        delete m_titlescreen;
        m_titlescreen = NULL;
    }
}

void MainMenuState::CheckEvent()
{
    while(m_engineInstance->GetGameWindow()->QueuedEvents())
    {
        sf::Event* Event = m_engineInstance->GetGameWindow()->GetEvent();
        if(Event->Type == sf::Event::Closed)
        {
            this->m_engineInstance->Running(false);
            m_engineInstance->GetGameWindow()->Close();
        }
        else if(Event->Type == sf::Event::JoyButtonPressed)
        {
            this->m_engineInstance->SwitchState(STATE_RANDOMREBOUND_GAMELEVEL);
        }
        else if(Event->Type == sf::Event::KeyPressed)
        {
            if(Event->Key.Code == sf::Key::Return)
            {
                this->m_engineInstance->SwitchState(STATE_RANDOMREBOUND_GAMELEVEL);
            }
        }
    }
}
void MainMenuState::UpdateLogic()
{
}
void MainMenuState::Paint()const
{
    GameWindow* gameWin = m_engineInstance->GetGameWindow();
    gameWin->Clear(sf::Color(77,77,77));
    m_titlescreen->Draw(*gameWin);
}
void MainMenuState::InitState()
{
    ImageResourceManager::LoadImageResource("StartScreen", "img/titlescreen.png");
    m_titlescreen = new GameSprite(Rect(0,0,640,480), Point(0,0), ImageResourceManager::GetImageResource("StartScreen"));
    m_theme = new sf::Music();
    m_theme->OpenFromFile("music/theme.wav");
}
void MainMenuState::EndState()
{
}
void MainMenuState::StartState()
{
    m_theme->SetLoop(true);
    m_theme->SetVolume(25);
    m_theme->Play();
    // pass ownership of the theme music to this track to the game over state
    m_engineInstance->SetObject(STATE_GAMEOVER,"theme_music", m_theme);
}
void MainMenuState::ExitState()
{
}

void MainMenuState::PauseState()
{
    this->Paused(true);
}
void MainMenuState::ResumeState()
{
    this->Paused(false);
}
void MainMenuState::SetInt(const std::string& key, int value)
{
}
void MainMenuState::SetFloat(const std::string& key, float value)
{
}
void MainMenuState::SetString(const std::string& key, const std::string& value)
{
}
void MainMenuState::SetObject(const std::string& key, void* value)
{
}
