#include "Game/Ball.h"

Ball::Ball(const Rect &dimensions, const Point &clipLocation, SDL_Texture *texture) : GameSprite(dimensions, clipLocation, texture)
{
    // ctor
    Alive(true);
    YSpeed(BALL_BASE_SPEED);
}

Ball::~Ball()
{
    // dtor
}
