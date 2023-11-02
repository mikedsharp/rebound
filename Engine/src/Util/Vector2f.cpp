#include "Util/Vector2f.h"

Vector2f::Vector2f()
{
    // ctor
    x = 0;
    y = 0;
}

Vector2f::Vector2f(int _x, int _y)
{
    // ctor
    x = _x;
    y = _y;
}

Vector2f operator+(Vector2f const &lhs, Vector2f const &rhs)
{
    Vector2f result((lhs.x + rhs.x), (lhs.y + rhs.y));
    return result;
}

Vector2f operator-(Vector2f const &lhs, Vector2f const &rhs)
{
    Vector2f result((lhs.x - rhs.x), (lhs.y - rhs.y));
    return result;
}

Vector2f::~Vector2f()
{
    // dtor
}
