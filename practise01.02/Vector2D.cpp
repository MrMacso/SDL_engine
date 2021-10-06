#include "Vector2D.h"


Vector2D::Vector2D(int x, int y)
{
    this-> x = x;
    this-> y = y;
}

int Vector2D::GetX() { return x;}
int Vector2D::GetY() { return y;}

void Vector2D::SetX(int x) { this->x = x;}
void Vector2D::SetY(int y) { this->y = y;}

Vector2D Vector2D::Add(const Vector2D& second)
{
    Vector2D result;

    result.x = x + second.x;
    result.y = y + second.y;

    return  result;
}

Vector2D Vector2D::Subtract(const Vector2D& second)
{
    Vector2D result;

    result.x = x - second.x;
    result.y = y - second.y;

    return result;
}

Vector2D Vector2D::Scale(int scaler)
{
    Vector2D result;

    result.x = x * scaler;
    result.y = y * scaler;

    return result;
}

int Vector2D::Distance(const Vector2D& second)
{
    Vector2D temp = Subtract(second);

    return static_cast<int>(temp.Magnitude());
}

double Vector2D::Magnitude()
{
    double x = static_cast<double>(this->x);
    double y = static_cast<double>(this->y);

    return sqrt((x * x) + (y * y));
}

Vector2D Vector2D::Negation()
{
    Vector2D result;

    result.x = -x;
    result.y = -y;

    return result;
}
