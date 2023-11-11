#include "States/MainMenuState.h"
#include "Util/ImageResourceManager.h"
#include "Util/AudioResourceManager.h"
#include "Util/Point.h"
#include "Util/Rect.h"

MainMenuState::MainMenuState() : GameState(NULL, STATE_MAINMENU)
{
    m_titlescreen = NULL;
    m_theme = NULL;
}

MainMenuState::~MainMenuState()
{
    // dtor
    if (m_titlescreen)
    {
        delete m_titlescreen;
        m_titlescreen = NULL;
    }

    AudioResourceManager::RemoveMusicResource("GameTheme");
}

void MainMenuState::CheckEvent()
{
    // Handle events on queue
    GameWindow *gameWin = m_engineInstance->GetGameWindow();
    SDL_Event *e = gameWin->GetEvent();
    while (SDL_PollEvent(e) != 0)
    {
        // User requests quit
        if (e->type == SDL_QUIT)
        {
            m_engineInstance->Running(false);
        }
    }
    // while (m_engineInstance->GetGameWindow()->QueuedEvents())
    // {
    //     // int *Event = m_engineInstance->GetGameWindow()->GetEvent();
    //     // if (Event->type == sf::Event::Closed)
    //     // {
    //     //     this->m_engineInstance->Running(false);
    //     //     m_engineInstance->GetGameWindow()->Close();
    //     // }
    //     // else if (Event->type == sf::Event::JoystickButtonPressed)
    //     // {
    //     //     this->m_engineInstance->SwitchState(STATE_RANDOMREBOUND_GAMELEVEL);
    //     // }
    //     // else if (Event->type == sf::Event::KeyPressed)
    //     // {
    //     //     if (Event->key.code == sf::Keyboard::Return)
    //     //     {
    //     //         this->m_engineInstance->SwitchState(STATE_RANDOMREBOUND_GAMELEVEL);
    //     //     }
    //     // }
    // }
}
void MainMenuState::UpdateLogic()
{
}
void MainMenuState::Paint() const
{
    SDL_Rect purpleSquare = {0, 0, 320, 240};
    GameWindow *gameWin = m_engineInstance->GetGameWindow();
    SDL_SetRenderDrawColor(gameWin->m_renderer, 0, 255, 255, 255);
    SDL_RenderFillRect(gameWin->m_renderer, &purpleSquare);
    // m_titlescreen->Draw(*gameWin);
    //  std::cout << "Drawing screen..." << std::endl;
}
void MainMenuState::InitState()
{
    ImageResourceManager::LoadImageResource("StartScreen", "img/titlescreen.png");
    m_theme = AudioResourceManager::LoadMusicResource("GameTheme", "music/theme.wav");
    m_titlescreen = new GameSprite(Rect(0, 0, 640, 480), Point(0, 0));
}
void MainMenuState::EndState()
{
}
void MainMenuState::StartState()
{
    MusicPlayer::Play(m_theme, true);
    // pass ownership of the theme music to this track to the game over state
    // m_engineInstance->SetObject(STATE_GAMEOVER, "theme_music", m_theme);
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
void MainMenuState::SetInt(const std::string &key, int value)
{
}
void MainMenuState::SetFloat(const std::string &key, float value)
{
}
void MainMenuState::SetString(const std::string &key, const std::string &value)
{
}
void MainMenuState::SetObject(const std::string &key, void *value)
{
}
