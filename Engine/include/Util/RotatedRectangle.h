#ifndef ROTATEDRECTANGLE_H
#define ROTATEDRECTANGLE_H

#include <Util/Rect.h>
#include <Util/Vector2f.h>

class RotatedRectangle
{
public:
    RotatedRectangle(const Rect &sourceRect, float rotationAngle);
    virtual ~RotatedRectangle();

    float X() const { return m_collisionRectangle.X(); }
    float Y() const { return m_collisionRectangle.Y(); }
    float Width() const { return m_collisionRectangle.Width(); }
    float Height() const { return m_collisionRectangle.Height(); }
    float Rotation() const { return m_rotation; }

    void Rotation(float rotation) { m_rotation = rotation; }
    void X(float x) { m_collisionRectangle.X(x); }
    void Y(float y) { m_collisionRectangle.Y(y); }
    void Width(float width) { m_collisionRectangle.Width(width); }
    void Height(float height) { m_collisionRectangle.Height(height); }

    void SetPosition(float x, float y)
    {
        m_collisionRectangle.SetPosition(x, y);
    }
    void SetSize(float width, float height)
    {
        m_collisionRectangle.SetSize(width, height);
    }
    void SetDimensions(float x, float y, float width, float height)
    {
        m_collisionRectangle.SetDimensions(x, y, width, height);
    }

    void UpperRightCorner(Vector2f &corner) const;
    void UpperLeftCorner(Vector2f &corner) const;
    void LowerRightCorner(Vector2f &corner) const;
    void LowerLeftCorner(Vector2f &corner) const;

    const Vector2f &Origin() const { return m_origin; }

    void RotatePoint(const Vector2f &thePoint, const Vector2f &theOrigin, float theRotation, Vector2f &translatedPoint) const;

    int GenerateScalar(const Vector2f &theRectangleCorner, const Vector2f &theAxis);

    bool Collision(Rect obstacle);
    bool Collision(const RotatedRectangle &obstacle);

    bool AxisCollision(RotatedRectangle obstacle, Vector2f axis);

protected:
private:
    Rect m_collisionRectangle;
    float m_rotation;
    Vector2f m_origin;
};

#endif // ROTATEDRECTANGLE_H
