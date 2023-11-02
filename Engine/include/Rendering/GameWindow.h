#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "Rendering/GameSprite.h"
// #include <SFML/System.hpp>
// #include <SFML/Window.hpp>
// #include <SFML/Graphics.hpp>
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
        // m_windowObj->clear(colour);
        std::cout << "Clearing windows" << std::endl;
    }
    bool QueuedEvents() const
    {
        std::cout << "simulate event polling" << std::endl;
        // return m_windowObj->pollEvent(*m_eventObj);
        return false;
    }
    int *GetEvent() const
    {
        return 0;
        // return m_eventObj;
    }
    void Draw(const GameSprite *wrappedSprite) const;
    void Display() const
    {
        std::cout << "simulate window.display" << std::endl;
        // m_windowObj->display();
    }
    void Close()
    {
        std::cout << "simulate window close" << std::endl;
        // m_windowObj->close();
    }

protected:
private:
    // sf::RenderWindow *m_windowObj;
    // sf::Event *m_eventObj;
    int m_width, m_height, m_bpp;
    std::string m_caption;
};

#endif // GAMEWINDOW_H
