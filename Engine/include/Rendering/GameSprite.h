#ifndef GAMESPRITE_H
#define GAMESPRITE_H

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include"Util/Rect.h"
#include <Util/RotatedRectangle.h>
#include"Util/Point.h"

#include<Rendering/GameWindow.h>
#include"Rendering/Drawable.h"

class GameWindow;

enum Direction {DIRECTION_UP = 0, DIRECTION_DOWN, DIRECTION_LEFT, DIRECTION_RIGHT, DIRECTION_AUTO};

class GameSprite : public Drawable
{
public:
    GameSprite(const Rect&  dimensions , const Point&  clipLocation , const sf::Image& spriteSheet);

    void SetSize(int width, int height);
    void SetPosition(float x, float y);
    void SetDimensions(int x, int y, int width, int height);
    void SetClipPosition(int x, int y);
    void SetAnimation(int action);
    void SetSpritesheet(const sf::Image& spriteSheet);
    void UpdateCameraPosition(float x, float y);
    bool Collision(const RotatedRectangle& obstacle);

    sf::Sprite* GetBaseSprite() const
    {
        return m_wrappedSprite;
    };

    int XSpeed()const
    {
        return m_xSpeed;
    }
    int YSpeed()const
    {
        return m_ySpeed;
    }

    void XSpeed(int xSpeed)
    {
        this->m_xSpeed = xSpeed;
    }
    void YSpeed(int ySpeed)
    {
        this->m_ySpeed = ySpeed;
    }

    bool Visible()const
    {
        return m_visible;
    }
    void Visible(bool visible)
    {
        m_visible = visible;
    }
    bool Alive()const
    {
        return m_alive;
    }
    void Alive(bool alive)
    {
        m_alive = alive;
    }
    bool Animating()
    {
        return m_animating;
    }
    void Animating(bool animating)
    {
        m_animating = animating;
    }

    RotatedRectangle& Bounds()
    {
        if(!m_bounds){
            m_bounds = new RotatedRectangle(Rect(m_worldX, m_worldY, m_width, m_height), 0);
        }
        return *m_bounds;
    }
    int FrameCount()const{return m_numFrames;}
    int CurrentFrame()const{return m_currentFrame;}
    void CurrentFrame(int currentFrame){
        m_currentFrame = currentFrame;
        SetClipPosition(Bounds().Width() * (m_currentFrame),m_clipY);
    }
    void FrameCount(int frames){m_numFrames = 1;}
    virtual void Move(int direction);
    virtual void Move(float offsetX, float offsetY);
    virtual void Draw(const GameWindow& win);
    virtual void Update()
    {

    };
    virtual void Kill(){;}

    virtual ~GameSprite();
protected:

private:
    float m_xSpeed, m_ySpeed;
    int m_width,  m_height;
    int m_clipX, m_clipY;
    bool m_visible;
    bool m_alive;
    bool m_animating;
    sf::Sprite* m_wrappedSprite;
   // Rect* m_bounds;
   RotatedRectangle* m_bounds;
   sf::Clock m_animationTimer;
   int m_currentFrame;
   int m_numFrames;
   float m_animationDelay;
};

#endif // GAMESPRITE_H
