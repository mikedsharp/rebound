#ifndef TILELAYER_H
#define TILELAYER_H

#include <Util/Composite.h>
#include <Rendering/Drawable.h>

#include <Game/Tile.h>
#include <Util/Dimension.h>
#include <Util/Point.h>
#include <Util/Rect.h>
#include <Util/RotatedRectangle.h>

#include <string>
#include <vector>

class TileLayer : public Composite, public Drawable
{
public:
    TileLayer(int tileX, int tileY, const Point &initialPosition, const Dimension &tileDims, const std::string &layerName, int zPos = 0);
    virtual ~TileLayer();

    void SetMapSize(int xTiles, int yTiles);
    void SetTileSize(int width, int height);
    void SetTilesheet(const std::string &newSheet);
    void LayerVisible(bool b);
    bool LayerVisible() const;
    void SetPosition(float x, float y);
    Tile *GetTile(int x, int y) const;
    Tile *GetCollidingTile(const RotatedRectangle &obstacle) const;

    virtual void Draw(const GameWindow &win);
    virtual void UpdateLogic();
    void UpdateCameraPosition(float x, float y);

    std::string Name() const { return m_layerName; }

    bool operator()(const TileLayer *a, const TileLayer *b) const
    {
        return a->GetZPosition() < b->GetZPosition();
    }
    virtual void Kill() {}

protected:
private:
    int m_tileX, m_tileY;
    int m_tileWidth, m_tileHeight;
    bool m_visible;
    std::vector<Tile *> m_tiles;
    std::string m_layerName;
};

#endif // TILELAYER_H
