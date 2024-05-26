#define SDL_MAIN_HANDLED

#ifdef _WIN32
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#elif __APPLE__
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_image.h>
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>
#endif

#include <iostream>
#include <GameEngine.h>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#include <emscripten/bind.h>
#include "Util/JavascriptCallbackHandler.h"

#endif
#include <iostream>
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

struct context
{
    GameEngine *engineInstance;
    float nowTime;
    float startTime;
};

#ifdef __EMSCRIPTEN__
EMSCRIPTEN_BINDINGS(my_module)
{
    emscripten::function("toggleMusic", &JavascriptCallbackHandler::ToggleMusic);
    emscripten::function("muteMasterVolume", &JavascriptCallbackHandler::MuteMasterVolume);
    emscripten::function("unmuteMasterVolume", &JavascriptCallbackHandler::UnmuteMasterVolume);
}
#endif

void mainloop(void *arg)
{
    struct context *ctx = static_cast<context *>(arg);

#ifdef __EMSCRIPTEN__
    ctx->engineInstance->RunLoop();
#else
    ctx->nowTime = SDL_GetTicks();
    if ((ctx->nowTime - ctx->startTime) > 33.3333333333)
    {
        ctx->engineInstance->RunLoop();
        ctx->startTime = SDL_GetTicks();
    }
#endif
}

int main(int argc, char *args[])
{
    GameEngine *instance = NULL;
    struct context ctx;
    instance = new GameEngine();
    ctx.engineInstance = instance;
    // invoke the engine, passing it the dimensions of our window and enter into a loop
    instance->InvokeEngine(640, 480, 32, "Rebound!");

    ctx.nowTime = SDL_GetTicks();
    ctx.startTime = SDL_GetTicks();

#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop_arg(mainloop, &ctx, 30, 1);
#else
    float nowTime;
    float startTime = SDL_GetTicks();

    while (instance->Running())
    {
        mainloop(&ctx);
    }

#endif
    SDL_Quit();
    IMG_Quit();
    Mix_Quit();
    return 0;
}
