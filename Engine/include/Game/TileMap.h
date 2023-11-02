#ifndef TILEMAP_H
#define TILEMAP_H

#include <Util/Composite.h>
#include <Util/Dimension.h>
#include <Rendering/Drawable.h>
#include <Game/Tile.h>
#include <Game/TileLayer.h>
#include <vector>
#include <Util/RotatedRectangle.h>

class TileMap : public Drawable, public Composite
{
public:
    TileMap(const std::string &fileName);
    Tile *GetCollidingTile(const RotatedRectangle &obstacle, const std::string &layerName) const;
    Tile *GetTile(int x, int y, const std::string &layerName) const;
    void LoadFromFile(const std::string &fileName);
    void SaveToFile(const std::string &fileName);
    void LayerVisible(const std::string &layerName, bool visible);
    bool LayerVisible(const std::string &layerName);
    void SetPosition(float x, float y);
    void SetMapSize(int xTiles, int yTiles);
    void SetTileSize(int width, int height);
    void SetTilesheet(const std::string &layerName, const std::string &newSheet);
    void SetLayerZPosition(const std::string &layerName, int order);
    virtual void Draw(const GameWindow &win);
    virtual bool HandleEvent();
    virtual void UpdateLogic();
    virtual void Kill() {}
    void UpdateCameraPosition(float x, float y);
    virtual ~TileMap();
    TileLayer *GetLayer(const std::string &layerName) const;
    const Dimension &GetMapDimensions()
    {
        if (m_mapDimensions)
        {
            return *m_mapDimensions;
        }
        else
        {
            // dimensions not allocated, allocate them now
            calcMapSize();
            return *m_mapDimensions;
        }
    }

protected:
    void removeLayer(const std::string &layerName);
    void calcMapSize();

private:
    int m_tileWidth, m_tileHeight;
    int m_tileX, m_tileY;
    Dimension *m_mapDimensions;
    std::vector<TileLayer *> m_layers;
};
#endif // TILEMAP_H
