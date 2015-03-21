#ifndef ROTATEDRECTANGLE_H
#define ROTATEDRECTANGLE_H

#include<Util/Rect.h>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class RotatedRectangle
{
    public:
        RotatedRectangle(const Rect& sourceRect, float rotationAngle);
        virtual ~RotatedRectangle();

        float X()const{return m_collisionRectangle.X();}
        float Y()const{return m_collisionRectangle.Y();}
        float Width()const{return m_collisionRectangle.Width();}
        float Height()const{return m_collisionRectangle.Height();}
        float Rotation()const{return m_rotation;}

        void Rotation(float rotation){ m_rotation = rotation;}
        void X(float x){m_collisionRectangle.X(x);}
        void Y(float y){m_collisionRectangle.Y(y);}
        void Width(float width){m_collisionRectangle.Width(width);}
        void Height(float height){m_collisionRectangle.Height(height);}

        void SetPosition(float x, float y)
        {
            m_collisionRectangle.SetPosition(x,y);
        }
        void SetSize(float width, float height)
        {
            m_collisionRectangle.SetSize(width, height);
        }
        void SetDimensions(float x, float y, float width, float height)
        {
            m_collisionRectangle.SetDimensions(x,y,width,height);
        }

        void UpperRightCorner(sf::Vector2f& corner)const;
        void UpperLeftCorner(sf::Vector2f& corner)const;
        void LowerRightCorner(sf::Vector2f& corner)const;
        void LowerLeftCorner(sf::Vector2f& corner)const;

        const sf::Vector2f& Origin()const{return m_origin;}

        void RotatePoint(const sf::Vector2f& thePoint,const sf::Vector2f& theOrigin ,float theRotation, sf::Vector2f& translatedPoint )const;

        int GenerateScalar(const sf::Vector2f& theRectangleCorner, const sf::Vector2f& theAxis);

        bool Collision(Rect obstacle);
        bool Collision(const RotatedRectangle& obstacle);

        bool AxisCollision(RotatedRectangle obstacle, sf::Vector2f axis);

    protected:
    private:
        Rect m_collisionRectangle;
        float m_rotation;
        sf::Vector2f m_origin;

};

#endif // ROTATEDRECTANGLE_H
