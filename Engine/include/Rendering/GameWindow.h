#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "Rendering/GameSprite.h"

#include <SDL.h>
#include <iostream>
#include <string>

class Drawable;
class GameSprite;

class GameWindow
{
public:
    GameWindow(int width, int height, int bpp, const std::string &caption);
    ~GameWindow();
    void Resize(int width, int height);
    void Clear(int r, int g, int b)
    {
        SDL_SetRenderDrawColor(this->m_renderer, r, g, b, 255);
        SDL_RenderClear(this->m_renderer);
    }
    SDL_Event *GetEvent()
    {
        return &this->m_eventObj;
    }
    void Draw(const GameSprite *wrappedSprite) const;
    void Display() const
    {
        SDL_RenderPresent(this->m_renderer);
    }
    void Close()
    {
        SDL_Quit();
    }
    SDL_Window *m_windowObj;
    SDL_Renderer *m_renderer;

protected:
private:
    SDL_Event m_eventObj;
    int m_width, m_height, m_bpp;
    std::string m_caption;
};

#endif // GAMEWINDOW_H
