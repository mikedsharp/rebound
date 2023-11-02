#include "Rendering/GameWindow.h"
#include <iostream>
GameWindow::GameWindow(int width, int height, int bpp, const std::string &caption)
{
    // ctor
    //  m_windowObj = new sf::RenderWindow();
    //  m_windowObj->create(sf::VideoMode(width, height, bpp), caption,sf::Style::Close);

    this->m_width = width;
    this->m_height = height;
    this->m_bpp = bpp;

    // m_eventObj = new sf::Event();
}

GameWindow::~GameWindow()
{
    // if (m_eventObj)
    // {
    //     delete m_eventObj;
    //     m_eventObj = NULL;
    // }
    // if (m_windowObj)
    // {
    //     delete m_windowObj;
    //     m_windowObj = NULL;
    // }
}

void GameWindow::Resize(int width, int height)
{
    // m_windowObj->create(sf::VideoMode(width, height, this->m_bpp), this->m_caption, sf::Style::Close);
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
