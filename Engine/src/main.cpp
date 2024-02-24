#define SDL_MAIN_HANDLED
#include <SDL.h>
#include <iostream>
#include <GameEngine.h>

#include <SDL_mixer.h>
#include <SDL_image.h>
#ifdef __EMSCRIPTEN__
#include <emscripten.h>
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

void mainloop(void *arg)
{
    struct context *ctx = static_cast<context *>(arg);
    ctx->nowTime = SDL_GetTicks();
    if ((ctx->nowTime - ctx->startTime) > 33.3333333333)
    {
        ctx->engineInstance->RunLoop();
        ctx->startTime = SDL_GetTicks();
    }
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
    emscripten_set_main_loop_arg(mainloop, &ctx, -1, 1);
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
