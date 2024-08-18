#include "GameStateFactory.h"
// use this with caution, including the implementation works, but is it the right thing to do?
#include "../../../rebound-engine/src/GameState.h"
#include "./MainMenuState.h"
#include "./GameOverState.h"
#include "./RandomRebound_GameState.h"

GameStateFactory::GameStateFactory()
{
    // ctor
}

GameStateFactory::~GameStateFactory()
{
    // dtor
}

GameState *GameStateFactory::BuildState(int stateType)
{
    // try to determine which type of state needs building, then allocate and return in
    switch (stateType)
    {
    case STATE_MAINMENU:
    {
        return new MainMenuState();
        break;
    }
    case STATE_GAMEPLAYAREA_GAMELEVEL :
    {
        return new RandomRebound_GameState();
        break;
    }
    case STATE_GAMEOVER:
    {
        return new GameOverState();
        break;
    }
    default:
    {
        std::cout << "Error: Invalid State Requested " << std::endl;
        exit(EXIT_FAILURE);
    }
    }
    return NULL;
}
