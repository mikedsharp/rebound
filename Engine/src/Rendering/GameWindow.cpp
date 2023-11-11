#include "Rendering/GameWindow.h"
#include <iostream>
struct context
{
    SDL_Renderer *renderer;
    SDL_Rect dest;
    SDL_Rect purpleSquare;
};

GameWindow::GameWindow(int width, int height, int bpp, const std::string &caption)
{
    // ctor
    this->m_width = width;
    this->m_height = height;
    this->m_bpp = bpp;

    struct context ctx;

    ctx.purpleSquare.x = 320;
    ctx.purpleSquare.y = 240;
    ctx.purpleSquare.w = 32;
    ctx.purpleSquare.h = 32;

    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

    SDL_Rect purpleSquare = {0, 0, 320, 240};
    SDL_Window *window = NULL;
    SDL_Renderer *renderer = NULL;
    SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);
    SDL_SetWindowTitle(window, "Rebound");
    SDL_Event event;
    m_eventObj = event;
    m_renderer = renderer;
    m_windowObj = window;
}

GameWindow::~GameWindow()
{
    if (m_renderer)
    {
        SDL_DestroyRenderer(m_renderer);
    }
    if (m_windowObj)
    {
        SDL_DestroyWindow(m_windowObj);
    }
}

void GameWindow::Resize(int width, int height)
{
    SDL_SetWindowSize(m_windowObj, width, height);
    this->m_width = width;
    this->m_height = height;
}

void GameWindow::Draw(const GameSprite *wrappedSprite) const
{
    if (wrappedSprite)
    {
        // this->m_windowObj->draw(*wrappedSprite->GetBaseSprite());
    }
    else
    {
        std::cout << "Error: Sprite is NULL, thus can't be drawn" << std::endl;
    }
}
