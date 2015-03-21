#include "Game/Tile.h"

Tile::Tile(const Rect& dimensions, const Point& clip, const sf::Image& spritesheet): GameSprite(dimensions, clip, spritesheet)
{
    m_type = 0;

    //ctor
}

Tile::~Tile()
{
    //dtor
}
