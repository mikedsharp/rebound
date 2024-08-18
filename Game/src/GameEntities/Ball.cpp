#include "./Ball.h"

Ball::Ball(const Rect &dimensions, const Point &clipLocation, SDL_Texture *texture) : GameSprite(dimensions, clipLocation, texture, 0)
{
    // ctor
    Alive(true);
    YSpeed(BALL_BASE_SPEED);
}

Ball::~Ball()
{
    // dtor
}
