#include "Game/Paddle.h"

Paddle::Paddle(const Rect &dimensions, const Point &clipLocation) : GameSprite(dimensions, clipLocation, NULL)
{
    // ctor
    Alive(true);
    XSpeed(10);
    m_score = 0;
}

Paddle::~Paddle()
{
    // dtor
}
