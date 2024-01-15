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
        ImageResourceManager::RemoveImageResource("StartScreen");
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
            break;
        }
        else if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_RETURN)
        {
            this->m_engineInstance->SwitchState(STATE_RANDOMREBOUND_GAMELEVEL);
            break;
        }
        else if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_ESCAPE)
        {
            this->m_engineInstance->Running(false);
            EndState();
            m_engineInstance->GetGameWindow()->Close();
            break;
        }
    }
}
void MainMenuState::UpdateLogic()
{
}
void MainMenuState::Paint() const
{
    GameWindow *gameWin = m_engineInstance->GetGameWindow();
    m_titlescreen->Draw(*gameWin);
    //  std::cout << "Drawing screen..." << std::endl;
}
void MainMenuState::InitState()
{
    GameWindow *gameWin = m_engineInstance->GetGameWindow();
    ImageResourceManager::LoadImageResource("StartScreen", "img/titlescreen.png", gameWin->m_renderer);
    m_theme = AudioResourceManager::LoadMusicResource("GameTheme", "music/theme.wav");
    m_titlescreen = new GameSprite(Rect(0, 0, 640, 480), Point(0, 0), ImageResourceManager::GetImageResource("StartScreen"));
}
void MainMenuState::EndState()
{
    // pass ownership of the theme music to this track to the game over state
    m_engineInstance->SetObject(STATE_GAMEOVER, "theme_music", m_theme);
}
void MainMenuState::StartState()
{
    MusicPlayer::Play(m_theme, true);
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
