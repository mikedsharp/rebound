#include "Game/Ball.h"

Ball::Ball(const Rect &dimensions, const Point &clipLocation) : GameSprite(dimensions, clipLocation)
{
    // ctor
    Alive(true);
    YSpeed(BALL_BASE_SPEED);
}

Ball::~Ball()
{
    // dtor
}
