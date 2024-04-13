#include "Game/Tile.h"

Tile::Tile(const Rect &dimensions, const Point &clip) : GameSprite(dimensions, clip, NULL, 0)
{
    m_type = 0;

    // ctor
}

Tile::~Tile()
{
    // dtor
}
