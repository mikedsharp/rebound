#ifndef RECT_H
#define RECT_H

class Rect
{
public:
    Rect(float x, float y, float width, float height)
    {
        SetDimensions(x,y,width,height);
    }
    Rect()
    {
        SetDimensions(0,0,0,0);
    }
    float X()const
    {
        return m_x;
    }
    void X(float x)
    {
        this->m_x = x;
    }
    float Y()const
    {
        return m_y;
    }
    void Y(float y)
    {
        this->m_y= y;
    }
    float Width()const
    {
        return m_width;
    }
    void Width(float width)
    {
        this->m_width = width;
    }
    float Height()const
    {
        return m_height;
    }
    void Height(float height)
    {
        this->m_height = height;
    }

    void SetPosition(float x, float y)
    {
        this->m_x = x;
        this->m_y = y;
    }
    void SetSize(float width, float height)
    {
        this->m_width = width;
        this->m_height = height;
    }
    void SetDimensions(float x, float y, float width, float height)
    {
        this->m_x = x;
        this->m_y = y;
        this->m_width = width;
        this->m_height = height;

    }
    virtual ~Rect();
protected:

private:
    float m_x, m_y, m_width, m_height;
};

#endif // RECT_H
