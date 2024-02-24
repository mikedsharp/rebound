#ifndef DRAWABLE_H
#define DRAWABLE_H

class GameWindow;

class Drawable
{
public:
    Drawable();
    virtual ~Drawable();
    virtual void Draw(const GameWindow &win) = 0;
    virtual void SetPosition(float x, float y) = 0;
    const int GetZPosition() const { return this->m_z; }
    void SetZPosition(int z) { this->m_z = z; }
    void SetWorldPosition(float x, float y);
    virtual void UpdateCameraPosition(float x, float y) = 0;

protected:
    int m_z;
    int m_worldX, m_worldY;
    int m_cameraX, m_cameraY;

private:
};

#endif // DRAWABLE_H
