#include "GameState.h"
GameState::GameState(GameEngine* ge, int stateType):m_engineInstance(ge),m_stateType(stateType)
{
    this->m_paused = false;
    this->m_engineInstance =  ge;
    this->m_stateType = stateType;
    this->m_initiated = false;
    //ctor
}

GameState::~GameState()
{
    //dtor
}
