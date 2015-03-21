#include "Game/Crate.h"

Crate::Crate(const Rect&  dimensions , int crateType , const sf::Image& spriteSheet):GameSprite(dimensions,Point(0,0) ,spriteSheet)
{
    //ctor
    Alive(true);
    m_crateType = crateType;
    SetClipPosition(Bounds().Width()*m_crateType, 0);
}
void Crate::Type(int type)
{
    m_crateType = type;
    SetClipPosition(Bounds().Width()*m_crateType, 0);
}
int Crate::Type()
{
    return m_crateType;
}

Crate::~Crate()
{
    //dtor
}
