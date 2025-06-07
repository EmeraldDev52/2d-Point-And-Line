#include "../include/Geo2d/Vector2d.h"
#include "../include/Geo2d/OrientationEnum.h"
#include <iostream>
#include <cmath>



namespace Geo2d{
    //constructor
    Vector2d::Vector2d(double x, double y) 
        : m_x{x}
        , m_y{y}
    {}   


    //operator overloads
    Vector2d Vector2d::operator+(const Vector2d& other) const {
        return Vector2d(this->m_x + other.m_x, this->m_y + other.m_y);
    }
        Vector2d Vector2d::operator-(const Vector2d& other) const{
        return Vector2d(this->m_x - other.m_x, this->m_y - other.m_y);
    }


    // prints the position of the points
    void Vector2d::print() const
    {
        std::cout << "Vector2d: " << m_x << ", " << m_y << std::endl;
    }


    // returns the magnitude of the vector
    double Vector2d::magnitude() const {
        return std::hypot(this->m_x, this->m_y);
    }


    // returns the normalized vector
    Vector2d Vector2d::normalized() const{
        double mag = magnitude();
        if (mag == 0.0) return Vector2d(0, 0); // Avoid division by zero
        return Vector2d(m_x / mag, m_y / mag);
    }





    //CONSTS
    const Vector2d Vector2d::ZERO = Vector2d(0.0, 0.0);
    const Vector2d Vector2d::UP = Vector2d(0.0, 1.0);
    const Vector2d Vector2d::DOWN = Vector2d(0.0, -1.0);
    const Vector2d Vector2d::LEFT = Vector2d(-1.0, 0.0);
    const Vector2d Vector2d::RIGHT = Vector2d(1.0, 0.0);
}