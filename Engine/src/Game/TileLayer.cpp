#include "Game/TileLayer.h"

TileLayer::TileLayer(int tileX, int tileY, const Point& initialPosition, const Dimension& tileDims, const sf::Texture& spriteSheet, const std::string& layerName, int zPos):Composite()
{
    //ctor
    // assign what we need to keep tiles correct
    this->m_tileX = tileX;
    this->m_tileY = tileY;

    this->m_worldX = initialPosition.X();
    this->m_worldY = initialPosition.Y();

    this->m_tileWidth = tileDims.Width();
    this->m_tileHeight = tileDims.Height();

    this->m_layerName = layerName;

    this->m_z = zPos;

    this->m_visible = true;

    // allocate the tiles, but provide incomplete parameters, the parent (containing) class will take care
    // of allocating the idividual stuff
    for(int j = 0; j < m_tileY; j++)
    {
        for(int i = 0; i < m_tileX; i++)
        {
            m_tiles.push_back(new Tile(Rect(0,0,0,0), Point(0,0), spriteSheet));
        }
    }
    SetPosition(this->m_worldX, this->m_worldY);
    SetTileSize(this->m_tileWidth,this->m_tileHeight);

    // as for everything else that needs to be set, the tilemap will explicitly set the tiles, the layer
    //doesnt know this information yet.
}
 TileLayer::~TileLayer()
{
    //dtor
    for(std::vector<Tile*>::iterator it = m_tiles.begin(); it < m_tiles.end(); it++)
    {
        if((*it) != NULL)
        {
            delete (*it);
            (*it) = NULL;
        }
    }
}

void TileLayer::SetMapSize(int xTiles, int yTiles)
{
    this->m_tileX = xTiles;
    this->m_tileY = yTiles;
}
void TileLayer::SetTileSize(int width, int height)
{
    this->m_tileWidth = width;
    this->m_tileHeight = height;

     std::vector<Tile*>::iterator it = m_tiles.begin();
    for(int j = 0; j < m_tileY;j++)
    {
        for(int i = 0; i < m_tileX; i++)
        {
            // set given position for each tile
            (*it)->SetSize(m_tileWidth,m_tileHeight);
            it++;
        }
    }
}
void TileLayer::SetTilesheet(const sf::Texture& newSheet )
{
     std::vector<Tile*>::iterator it = m_tiles.begin();
    for(int j = 0; j < m_tileY;j++)
    {
        for(int i = 0; i < m_tileX; i++)
        {
            // set given position for each tile
            (*it)->SetSpritesheet(newSheet);
            it++;
        }
    }

}

void TileLayer::LayerVisible(bool b)
{
    this->m_visible = b;
}
bool TileLayer::LayerVisible() const
{
    return m_visible;
}
void TileLayer::SetPosition(float x, float y)
{

    std::vector<Tile*>::iterator it = m_tiles.begin();
    for(int j = 0; j < m_tileY;j++)
    {
        for(int i = 0; i < m_tileX; i++)
        {
            // set given position for each tile
            (*it)->SetPosition((i*m_tileWidth)+x, (j*m_tileHeight)+y);
            it++;
        }
    }
}
Tile* TileLayer::GetTile(int x, int y)const
{
    return this->m_tiles[x +(y * m_tileX)];
}
Tile* TileLayer::GetCollidingTile(const RotatedRectangle& obstacle)const
{
    std::vector<Tile*>::const_iterator it = m_tiles.begin();
    for(int j = 0; j < m_tileY;j++)
    {
        for(int i = 0; i < m_tileX; i++)
        {
            // set given position for each tile
            if((*it)->Collision(obstacle)){
                return(*it);
            }
            it++;
        }
    }
    return NULL;
}

void TileLayer::Draw(const GameWindow& win)
{
    if(m_visible)
    {
        std::vector<Tile*>::const_iterator it = m_tiles.begin();
        for(int j = 0; j < m_tileY;j++)
        {
            for(int i = 0; i < m_tileX; i++)
            {
                // set given position for each tile
                win.Draw((*it));
                it++;
            }
        }
    }


}
bool TileLayer::HandleEvent(const sf::Event* event)
{
    return false;
}
void TileLayer::UpdateLogic()
{

}
void TileLayer::UpdateCameraPosition(float x, float y)
{
    // assign camera co-ordinates to the composite
    this->m_cameraX = x;
    this->m_cameraY = y;
    // ressign world position of map
    this->SetPosition(m_worldX, m_worldY);
    // update the camera for all component objects
    for(std::vector<Tile*>::iterator it = m_tiles.begin(); it < m_tiles.end(); it++)
    {
      (*it)->UpdateCameraPosition(m_cameraX,m_cameraY);
    }

}

