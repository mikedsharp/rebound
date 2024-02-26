#ifndef POINT_H
#define POINT_H

class Point
{
public:
    Point(float x, float y)
    {
        X(x);
        Y(y);
    }
    float X() const
    {
        return m_x;
    }
    void X(float x)
    {
        this->m_x = x;
    }
    float Y() const
    {
        return m_y;
    }
    void Y(float y)
    {
        this->m_y = y;
    }
    virtual ~Point();

protected:
private:
    float m_x;
    float m_y;
};

#endif // POINT_H
