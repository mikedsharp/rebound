#ifndef PADDLE_H
#define PADDLE_H

#include "../../../rebound-engine/src/Rendering/GameSprite.h"

class Paddle : public GameSprite
{
public:
    Paddle(const Rect &dimensions, const Point &clipLocation, SDL_Texture *texture);
    int Score() { return m_score; }
    void Score(int score) { m_score = score; }
    void AddScore(int score) { m_score += score; }
    virtual ~Paddle();

protected:
private:
    int m_score;
};

#endif // PADDLE_H
