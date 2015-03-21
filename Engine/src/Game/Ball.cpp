#include "Game/Ball.h"

Ball::Ball(const Rect&  dimensions , const Point&  clipLocation , const sf::Image& spriteSheet):GameSprite(dimensions,clipLocation ,spriteSheet)
{
    //ctor
    Alive(true);
    YSpeed(BALL_BASE_SPEED);
}

Ball::~Ball()
{
    //dtor
}
