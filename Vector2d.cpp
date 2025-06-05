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

Vector2d Vector2d::operator-(const Vector2d& other) const{
    return Vector2d(this->m_x - other.m_x, this->m_y - other.m_y);
}

double Vector2d::magnitude() const {
    return std::hypot(this->m_x, this->m_y);
}
Vector2d Vector2d::normalized() const{
    double mag = magnitude();
    if (mag == 0.0) return Vector2d(0, 0); // Avoid division by zero
    return Vector2d(m_x / mag, m_y / mag);
}



