#ifndef TILE_H
#define TILE_H

#include<Rendering/GameWindow.h>
#include <Rendering/GameSprite.h>
#include<iostream>
using namespace std;

class Tile : public GameSprite
{
public:
    Tile(const Rect& dimensions, const Point& clip, const sf::Image& spritesheet);
    virtual ~Tile();
    void Type(int type)
    {
        m_type = type;
    }
    int Type()const
    {
        return m_type;
    }
    virtual void Draw(GameWindow& win){
        GameSprite::Draw(win);
    }
    virtual void Kill(){}

protected:
private:
    int m_type;
};

#endif // TILE_H
