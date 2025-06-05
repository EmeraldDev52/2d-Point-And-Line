#pragma once
#include "orientationEnum.h"


// Vector2d class
class Vector2d
{
public:
    double m_x{0.0};
    double m_y{0.0};

    
    Vector2d() = default;

    Vector2d(double x, double y);
    Vector2d operator+(const Vector2d& other) const;
    Vector2d operator-(const Vector2d& other) const;

    double magnitude() const;

    Vector2d normalized() const;

    void print() const;


};