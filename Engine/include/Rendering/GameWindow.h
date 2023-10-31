#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "Rendering/GameSprite.h"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <string>

class Drawable;
class GameSprite;

class GameWindow
{
public:
    GameWindow(int width, int height, int bpp, const std::string& caption);
    ~GameWindow();
    void Resize(int width, int height);
    void Clear(const sf::Color& colour = sf::Color(0,0,0))
    {
        m_windowObj->clear(colour);
    }
    bool QueuedEvents()const
    {
        return m_windowObj->pollEvent(*m_eventObj);
    }
    sf::Event* GetEvent()const
    {
        return m_eventObj;
    }
    void Draw(const GameSprite* wrappedSprite)const;
    void Display()const
    {
        m_windowObj->display();
    }
    void Close()
    {
        m_windowObj->close();
    }
    sf::RenderWindow* GetRawWindow()const
    {
        return m_windowObj;
    }
protected:
private:
    sf::RenderWindow* m_windowObj;
    sf::Event* m_eventObj;
    int m_width, m_height, m_bpp;
    std::string m_caption;
};

#endif // GAMEWINDOW_H
