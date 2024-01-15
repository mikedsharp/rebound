#include "GameEngine.h"

//  #include <SFML/System.hpp>
#include <string>

using namespace std;

GameEngine::GameEngine()
{
    // ctor
    m_running = true;
}

GameEngine::~GameEngine()
{
    // dtor
    if (win != NULL)
    {
        delete win;
        win = NULL;
    }
    // removes all states from memory
    map<int, GameState *>::iterator it;
    for (it = m_states.begin(); it != m_states.end(); it++)
    {
        // delete the values in the map, they are pointers
        if ((*it).second)
        {
            delete (*it).second;
            (*it).second = NULL;
        }
    }
    // then clear the map
    m_states.clear();
}

void GameEngine::SwitchState(int stateType)
{
    // switch current game engine state to a given state;
    if (m_states.count(stateType) > 0)
    {
        m_currentState = m_states[stateType];
        m_currentState->EngineInstance(this);

        bool init;
        init = m_currentState->Initiated();
        if (!init)
        {
            m_currentState->Initiated(true);
            m_currentState->InitState();
            m_currentState->StartState();
        }
        else
        {
            m_currentState->StartState();
        }
    }
    else
    {
        std::cout << "Error:: Requested State Does not exist in Engine..." << std::endl;
    }
}
void GameEngine::RemoveState(int stateType)
{
    // remove a given state from state map
    if (m_states.count(stateType) > 0)
    {
        GameState *gs = m_states[stateType];
        if (gs != NULL)
        {
            // remove state from memory
            delete gs;
            gs = NULL;
        }
        // finally, remove the state pointer from the map
        m_states.erase(stateType);
        std::cout << "Message: State Deleted Successfully" << std::endl;
    }
    else
    {
        std::cout << "Error:: Requested State Does not exist in Engine..." << std::endl;
    }
}
void GameEngine::AddState(GameState *gs)
{
    // add a given state to state map by GameState pointer
    if (gs != NULL)
    {
        if (m_states.count(gs->StateType()) == 0)
        {
            m_states[gs->StateType()] = gs;
        }
        else
        {
            std::cout << "Error:: State Already Exists in engine..." << std::endl;
        }
    }
    else
    {
        std::cout << "Error:: State was NULL, it is likely that it was improperly allocated..." << std::endl;
    }
}
void GameEngine::InvokeEngine(int width, int height, int bpp, std::string caption)
{
    // init the window
    win = new GameWindow(width, height, bpp, caption);

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
    }

    // init other subsystems
    // init start state
    // begin loop, call state methods in sequence while running is true

    this->AddState(GameStateFactory::BuildState(STATE_MAINMENU));
    this->AddState(GameStateFactory::BuildState(STATE_GAMEOVER));
    this->AddState(GameStateFactory::BuildState(STATE_RANDOMREBOUND_GAMELEVEL));

    this->SwitchState(STATE_MAINMENU);

    float nowTime;
    float startTime = SDL_GetTicks();

    SDL_Event e;

    while (m_running)
    {

        // 30 fps?
        nowTime = SDL_GetTicks();
        if ((nowTime - startTime) > 33.3333333333)
        {
            m_currentState->CheckEvent();
            if (!m_currentState->Paused())
            {
                m_currentState->UpdateLogic();
            }
            win->Clear(255, 255, 0);
            m_currentState->Paint();
            win->Display();
            startTime = SDL_GetTicks();
        }
    }
}

// value  passing methods
void GameEngine::SetInt(int destinationState, const std::string &key, int value)
{
    m_states[destinationState]->SetInt(key, value);
}
void GameEngine::SetFloat(int destinationState, const std::string &key, float value)
{
    m_states[destinationState]->SetFloat(key, value);
}
void GameEngine::SetString(int destinationState, const std::string &key, const std::string &value)
{
    m_states[destinationState]->SetString(key, value);
}
void GameEngine::SetObject(int destinationState, const std::string &key, void *value)
{
    m_states[destinationState]->SetObject(key, value);
}
