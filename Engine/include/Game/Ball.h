#ifndef BALL_H
#define BALL_H

#include <Rendering/GameSprite.h>


const int BALL_BASE_SPEED = 5;

class Ball : public GameSprite
{
    public:
        Ball(const Rect&  dimensions , const Point&  clipLocation , const sf::Texture& spriteSheet);
        virtual ~Ball();
    protected:
    private:
};

#endif // BALL_H
