#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <iostream>
#include <GameEngine.h>
int main()
{
    // create main engine instance
    GameEngine *instance = NULL;
    instance = new GameEngine();
    // invoke the engine, passing it the dimensions of our window and enter into a loop
    instance->InvokeEngine(640, 480, 32, "Rebound!");

    SDL_Quit();
    Mix_Quit();
    return 0;
}
