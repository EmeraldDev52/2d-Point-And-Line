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
    void print() const;
    static double distance(const Vector2d& p1, const Vector2d& p2);
    double distance(const Vector2d& p2) const;

};