#ifndef VECTOR2F_H
#define VECTOR2F_H

class Vector2f
{
public:
    Vector2f();
    Vector2f(int x, int y);
    friend Vector2f operator+(Vector2f const &lhs, Vector2f const &rhs);
    friend Vector2f operator-(Vector2f const &lhs, Vector2f const &rhs);
    virtual ~Vector2f();
    int x, y;

protected:
private:
};

#endif // VECTOR2F_H
