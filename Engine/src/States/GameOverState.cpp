#include "States/GameOverState.h"
#include "Util/ImageResourceManager.h"
#include "Util/MusicPlayer.h"
#include <sstream>

GameOverState::GameOverState() : GameState(NULL, STATE_GAMEOVER)
{
    // ctor
    m_playerScore = 0;
    m_victory = 0;
    m_backdrop = NULL;
    // m_theme = NULL;
}

GameOverState::~GameOverState()
{
    // if (m_backdrop)
    // {
    //     delete m_backdrop;
    // }
    // if (m_theme)
    // {
    //     delete m_theme;
    //     m_theme = NULL;
    // }
}

void GameOverState::CheckEvent()
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
        else if (e->type == SDL_MOUSEBUTTONDOWN)
        {
            this->m_engineInstance->SwitchState(STATE_RANDOMREBOUND_GAMELEVEL);
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
        else if (e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_m)
        {
            MusicPlayer::ToggleMusic();
            break;
        }
    }
}

void GameOverState::UpdateLogic()
{
}

void GameOverState::Paint() const
{
    m_engineInstance->GetGameWindow()->Clear(0, 0, 0);
    m_backdrop->Draw(*m_engineInstance->GetGameWindow());
}

void GameOverState::InitState()
{
    GameWindow *gameWin = m_engineInstance->GetGameWindow();
    ImageResourceManager::LoadImageResource("gameover_lose", "assets/img/gameover_lose.png", gameWin->m_renderer);
    ImageResourceManager::LoadImageResource("gameover_win", "assets/img/gameover_win.png", gameWin->m_renderer);

    m_backdrop = new GameSprite(Rect(0, 0, 640, 480), Point(0, 0), NULL, 0);
}

void GameOverState::EndState()
{
    // if (m_theme)
    // {
    //     m_theme->stop();
    // }
}

void GameOverState::StartState()
{
    if (m_victory > 0)
    {
        m_backdrop->SetTexture(ImageResourceManager::GetImageResource("gameover_win"));
    }
    else
    {
        m_backdrop->SetTexture(ImageResourceManager::GetImageResource("gameover_lose"));
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
void GameOverState::SetInt(const std::string &key, int value)
{
    // players final victor/loss message
    if (key == "Outcome")
    {
        m_victory = value;
    }
}
void GameOverState::SetFloat(const std::string &key, float value)
{
}
void GameOverState::SetString(const std::string &key, const std::string &value)
{
}
void GameOverState::SetObject(const std::string &key, void *value)
{
}
