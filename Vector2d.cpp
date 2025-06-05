#include "Vector2d.h"
#include "OrientationEnum.h"
#include <iostream>
#include <cmath>

//constructor
Vector2d::Vector2d(double x, double y) 
    : m_x {x}
    , m_y {y}
{}   

//operator overloading for addition of points
Vector2d Vector2d::operator+(const Vector2d& other) const {
    return Vector2d(this->m_x + other.m_x, this->m_y + other.m_y);
}

// prints the position of the points
void Vector2d::print() const
{
    std::cout << "Vector2d: " << m_x << ", " << m_y << std::endl;
}

//gets the distance between two points
double Vector2d::distance(const Vector2d& p2) const
{
    return std::hypot(m_x - p2.m_x, m_y - p2.m_y);
}

double Vector2d::distance(const Vector2d& p1, const Vector2d& p2)
{
    return p1.distance(p2);
}






