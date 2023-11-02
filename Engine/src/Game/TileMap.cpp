#include "Game/TileMap.h"
#include "Util/ImageResourceManager.h"
#include <iostream>
TileMap::TileMap(const std::string &fileName)
{
    // ctor
    ImageResourceManager::LoadImageResource("Tiles2", "img/tileset.png");
    ImageResourceManager::LoadImageResource("Tiles", "img/tileset2.png");
    m_tileX = 35;
    m_tileY = 30;
    m_tileWidth = 32;
    m_tileHeight = 32;

    m_layers.push_back(new TileLayer(m_tileX, m_tileY, Point(0, 0), Dimension(m_tileWidth, m_tileHeight)));
    m_layers.push_back(new TileLayer(m_tileX, m_tileY, Point(0, 0), Dimension(m_tileWidth, m_tileHeight)));

    SetLayerZPosition("Collision", 1);
    SetLayerZPosition("Background", 5);
}
TileMap::~TileMap()
{
    // dtor
    for (std::vector<TileLayer *>::iterator it = m_layers.begin(); it < m_layers.end(); it++)
    {
        if ((*it) != NULL)
        {
            delete (*it);
            (*it) = NULL;
        }
    }
}

Tile *TileMap::GetCollidingTile(const RotatedRectangle &obstacle, const std::string &layerName) const
{
    for (std::vector<TileLayer *>::const_iterator it = m_layers.begin(); it < m_layers.end(); it++)
    {
        if ((*it)->Name() == layerName)
        {
            return (*it)->GetCollidingTile(obstacle);
        }
    }
    return NULL;
}
Tile *TileMap::GetTile(int x, int y, const std::string &layerName) const
{
    for (std::vector<TileLayer *>::const_iterator it = m_layers.begin(); it < m_layers.end(); it++)
    {
        if ((*it)->Name() == layerName)
        {
            return (*it)->GetTile(x, y);
        }
    }
    return NULL;
}
void TileMap::LoadFromFile(const std::string &fileName)
{
}
void TileMap::SaveToFile(const std::string &fileName)
{
}
void TileMap::LayerVisible(const std::string &layerName, bool visible)
{
    for (std::vector<TileLayer *>::iterator it = m_layers.begin(); it < m_layers.end(); it++)
    {
        if ((*it)->Name() == layerName)
        {
            (*it)->LayerVisible(visible);
            break;
        }
    }
}
bool TileMap::LayerVisible(const std::string &layerName)
{
    for (std::vector<TileLayer *>::iterator it = m_layers.begin(); it < m_layers.end(); it++)
    {
        if ((*it)->Name() == layerName)
        {
            return (*it)->LayerVisible();
        }
    }
    return false;
}
void TileMap::SetPosition(float x, float y)
{
    for (std::vector<TileLayer *>::iterator it = m_layers.begin(); it < m_layers.end(); it++)
    {
        (*it)->SetPosition(x, y);
    }
}
void TileMap::SetMapSize(int xTiles, int yTiles)
{
    for (std::vector<TileLayer *>::iterator it = m_layers.begin(); it < m_layers.end(); it++)
    {
        (*it)->SetMapSize(xTiles, yTiles);
    }
}
void TileMap::SetTileSize(int width, int height)
{
    for (std::vector<TileLayer *>::iterator it = m_layers.begin(); it < m_layers.end(); it++)
    {
        (*it)->SetTileSize(width, height);
    }
}
void TileMap::SetTilesheet(const std::string &layerName)
{
    for (std::vector<TileLayer *>::iterator it = m_layers.begin(); it < m_layers.end(); it++)
    {
        if ((*it)->Name() == layerName)
        {

            // (*it)->SetTilesheet(newSheet);
            break;
        }
    }
}
void TileMap::SetLayerZPosition(const std::string &layerName, int order)
{
    for (std::vector<TileLayer *>::iterator it = m_layers.begin(); it < m_layers.end(); it++)
    {
        if ((*it)->Name() == layerName)
        {
            (*it)->SetZPosition(order);
            break;
        }
    }

    for (unsigned int j = 0; j < m_layers.size() - 1; j++)
    {
        for (unsigned int i = 0; i < m_layers.size() - 1; i++)
        {
            if (m_layers[i]->GetZPosition() < m_layers[i + 1]->GetZPosition())
            {
                TileLayer *temp = NULL;
                temp = m_layers[i];
                m_layers[i] = m_layers[i + 1];
                m_layers[i + 1] = temp;
            }
        }
    }
}

void TileMap::Draw(const GameWindow &win)
{
    for (std::vector<TileLayer *>::const_iterator it = m_layers.begin(); it < m_layers.end(); it++)
    {
        TileLayer *tl;
        tl = (*it);
        tl->Draw(win);
    }
}
bool TileMap::HandleEvent()
{
    // if (event->type == sf::Event::KeyPressed)
    // {
    //     if (event->key.code == sf::Keyboard::Key::F)
    //     {
    //         std::cout << "F Key Pressed" << std::endl;
    //         return true;
    //     }
    //     else if (event->key.code == sf::Keyboard::Key::E)
    //     {
    //         std::cout << "E Key Pressed" << std::endl;
    //         return true;
    //     }
    // }
    return false;
}
void TileMap::UpdateLogic()
{
}
TileLayer *TileMap::GetLayer(const std::string &layerName) const
{
    for (unsigned int i = 0; i < m_layers.size(); i++)
    {
        if (m_layers[i]->Name() == layerName)
        {
            return m_layers[i];
        }
    }
    return NULL;
}
void TileMap::UpdateCameraPosition(float x, float y)
{
    this->m_cameraX = x;
    this->m_cameraY = y;
    this->SetPosition(m_worldX, m_worldY);

    for (std::vector<TileLayer *>::iterator it = m_layers.begin(); it < m_layers.end(); it++)
    {

        (*it)->UpdateCameraPosition(x, y);
    }
}
void TileMap::calcMapSize()
{
    if (m_mapDimensions)
    {
        delete m_mapDimensions;
        m_mapDimensions = NULL;
    }
    m_mapDimensions = new Dimension(m_tileWidth * m_tileX, m_tileHeight * m_tileY);
}
