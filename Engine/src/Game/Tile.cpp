#include "Game/Tile.h"

Tile::Tile(const Rect &dimensions, const Point &clip, const sf::Texture &spritesheet) : GameSprite(dimensions, clip)
{
    m_type = 0;

    // ctor
}

Tile::~Tile()
{
    // dtor
}
