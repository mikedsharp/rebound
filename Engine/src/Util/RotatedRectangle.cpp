#include "Util/RotatedRectangle.h"
#include <vector>
#include <iostream>
#include <cmath>
#define PI 3.14159265
RotatedRectangle::RotatedRectangle(const Rect &sourceRect, float rotationAngle)
{
    // ctor
    m_collisionRectangle.SetDimensions(sourceRect.X(), sourceRect.Y(), sourceRect.Width(), sourceRect.Height());
    m_rotation = rotationAngle;
    m_origin.x = (m_collisionRectangle.Width() / 2);
    m_origin.y = (m_collisionRectangle.Height() / 2);
}

RotatedRectangle::~RotatedRectangle()
{
    // dtor
}

void RotatedRectangle::RotatePoint(const Vector2f &thePoint, const Vector2f &theOrigin, float theRotation, Vector2f &translatedPoint) const
{
    translatedPoint.x = (float)(theOrigin.x + (thePoint.x - theOrigin.x) * (cos(theRotation)) - (thePoint.y - theOrigin.y) * (sin(theRotation)));
    translatedPoint.y = (float)(theOrigin.y + (thePoint.y - theOrigin.y) * (cos(theRotation)) + (thePoint.x - theOrigin.x) * (sin(theRotation)));
}

void RotatedRectangle::UpperRightCorner(Vector2f &corner) const
{
    corner.x = m_collisionRectangle.X() + m_collisionRectangle.Width();
    corner.y = m_collisionRectangle.Y();
    if (m_rotation != 0)
    {
        RotatePoint(corner, corner + Vector2f(-m_origin.x, m_origin.y), m_rotation, corner);
    }
}
void RotatedRectangle::UpperLeftCorner(Vector2f &corner) const
{
    corner.x = m_collisionRectangle.X();
    corner.y = m_collisionRectangle.Y();
    if (m_rotation != 0)
    {
        RotatePoint(corner, corner + m_origin, m_rotation, corner);
    }
}
void RotatedRectangle::LowerRightCorner(Vector2f &corner) const
{
    corner.x = m_collisionRectangle.X() + m_collisionRectangle.Width();
    corner.y = m_collisionRectangle.Y() + m_collisionRectangle.Height();
    if (m_rotation != 0)
    {
        RotatePoint(corner, corner + Vector2f(-m_origin.x, -m_origin.y), m_rotation, corner);
    }
}
void RotatedRectangle::LowerLeftCorner(Vector2f &corner) const
{
    corner.x = m_collisionRectangle.X();
    corner.y = m_collisionRectangle.Y() + m_collisionRectangle.Height();
    if (m_rotation != 0)
    {
        RotatePoint(corner, corner + Vector2f(m_origin.x, -m_origin.y), m_rotation, corner);
    }
}

int RotatedRectangle::GenerateScalar(const Vector2f &theRectangleCorner, const Vector2f &theAxis)
{
    float numerator = (theRectangleCorner.x * theAxis.x) + (theRectangleCorner.y * theAxis.y);
    float denominator = (theAxis.x * theAxis.x) + (theAxis.y * theAxis.y);
    float divisionResult = numerator / denominator;
    Vector2f cornerProjected;
    cornerProjected.x = divisionResult * theAxis.x;
    cornerProjected.y = divisionResult * theAxis.y;

    float scalar = (theAxis.x * cornerProjected.x) + (theAxis.y * cornerProjected.y);

    return (int)scalar;
}
bool RotatedRectangle::Collision(Rect obstacle)
{
    return Collision(RotatedRectangle(obstacle, 0.0f));
    return false;
}
bool RotatedRectangle::Collision(const RotatedRectangle &obstacle)
{

    std::vector<Vector2f> rectangleCorners;

    Vector2f a1;
    Vector2f a2;
    Vector2f a3;
    Vector2f a4;

    UpperLeftCorner(a1);
    UpperRightCorner(a2);
    LowerLeftCorner(a3);
    LowerRightCorner(a4);

    Vector2f b1;
    Vector2f b2;
    Vector2f b3;
    Vector2f b4;

    obstacle.UpperLeftCorner(b1);
    obstacle.UpperRightCorner(b2);
    obstacle.LowerLeftCorner(b3);
    obstacle.LowerRightCorner(b4);

    rectangleCorners.push_back(a2 - a1);
    rectangleCorners.push_back(a2 - a4);
    rectangleCorners.push_back(b1 - b3);
    rectangleCorners.push_back(b1 - b2);

    for (std::vector<Vector2f>::iterator it = rectangleCorners.begin(); it < rectangleCorners.end(); it++)
    {
        if (!AxisCollision(obstacle, (*it)))
        {
            return false;
        }
    }
    return true;
}

bool RotatedRectangle::AxisCollision(RotatedRectangle obstacle, Vector2f axis)
{
    std::vector<float> rectangleAScalars;

    Vector2f upperLeftA, upperRightA, lowerLeftA, lowerRightA;
    obstacle.UpperLeftCorner(upperLeftA);
    obstacle.UpperRightCorner(upperRightA);
    obstacle.LowerLeftCorner(lowerLeftA);
    obstacle.LowerRightCorner(lowerRightA);

    rectangleAScalars.push_back(GenerateScalar(upperLeftA, axis));
    rectangleAScalars.push_back(GenerateScalar(upperRightA, axis));
    rectangleAScalars.push_back(GenerateScalar(lowerLeftA, axis));
    rectangleAScalars.push_back(GenerateScalar(lowerRightA, axis));

    std::vector<float> rectangleBScalars;
    Vector2f upperLeftB, upperRightB, lowerLeftB, lowerRightB;

    UpperLeftCorner(upperLeftB);
    UpperRightCorner(upperRightB);
    LowerLeftCorner(lowerLeftB);
    LowerRightCorner(lowerRightB);

    rectangleBScalars.push_back(GenerateScalar(upperLeftB, axis));
    rectangleBScalars.push_back(GenerateScalar(upperRightB, axis));
    rectangleBScalars.push_back(GenerateScalar(lowerLeftB, axis));
    rectangleBScalars.push_back(GenerateScalar(lowerRightB, axis));

    float rectangleAMax(rectangleAScalars[0]);
    float rectangleAMin(rectangleAScalars[0]);
    float rectangleBMax(rectangleBScalars[0]);
    float rectangleBMin(rectangleBScalars[0]);

    for (std::vector<float>::iterator it = rectangleAScalars.begin(); it < rectangleAScalars.end(); it++)
    {
        if ((*it) > rectangleAMax)
        {
            rectangleAMax = (*it);
        }
        if ((*it) < rectangleAMin)
        {
            rectangleAMin = (*it);
        }
    }
    for (std::vector<float>::iterator it = rectangleBScalars.begin(); it < rectangleBScalars.end(); it++)
    {

        if ((*it) > rectangleBMax)
        {
            rectangleBMax = (*it);
        }
        if ((*it) < rectangleBMin)
        {
            rectangleBMin = (*it);
        }
    }

    if ((rectangleBMin <= rectangleAMax) && (rectangleBMax >= rectangleAMax))
    {
        return true;
    }
    else if (rectangleAMin <= rectangleBMax && rectangleAMax >= rectangleBMax)
    {
        return true;
    }

    return false;
}
