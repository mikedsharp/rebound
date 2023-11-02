#ifndef CRATE_H
#define CRATE_H

#include <Rendering/GameSprite.h>

enum CrateType
{
    CRATE_RANDOM = 0,
    CRATE_ONEUP,
    CRATE_ONEDOWN,
    CRATE_SLOWBALL,
    CRATE_SPEEDUPBALL,
    CRATE_TAKEPOINT,
    CRATE_CHANGETHEME,
    CRATE_REGENERATE
};

class Crate : public GameSprite
{
public:
    Crate(const Rect &dimensions, int crateType);
    void Type(int type);
    int Type();
    virtual ~Crate();

protected:
private:
    int m_crateType;
};

#endif // CRATE_H
