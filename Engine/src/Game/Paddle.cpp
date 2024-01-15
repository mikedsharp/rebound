#include "Game/Paddle.h"

Paddle::Paddle(const Rect &dimensions, const Point &clipLocation, SDL_Texture *texture) : GameSprite(dimensions, clipLocation, texture)
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
