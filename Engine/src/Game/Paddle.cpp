#include "Game/Paddle.h"

Paddle::Paddle(const Rect&  dimensions , const Point&  clipLocation , const sf::Texture& spriteSheet):GameSprite(dimensions,clipLocation ,spriteSheet)
{
    //ctor
    Alive(true);
    XSpeed(10);
    m_score = 0;
}

Paddle::~Paddle()
{
    //dtor
}
