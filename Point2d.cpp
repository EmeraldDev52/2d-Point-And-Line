#include "Point2d.h"
#include "OrientationEnum.h"
#include <iostream>
#include <cmath>

//constructor
Point2d::Point2d(double x, double y) 
    : m_x {x}
    , m_y {y}
{}   

//operator overloading for addition of points
Point2d Point2d::operator+(const Point2d& other) const {
    return Point2d(getX() + other.getX(), getY() + other.getY());
}

// prints the position of the points
void Point2d::print() const
{
    std::cout << "Point2d: " << m_x << ", " << m_y << std::endl;
}

//gets the distance between two points
double Point2d::distance(const Point2d& p2) const
{
    return std::hypot(m_x - p2.getX(), m_y - p2.getY());
}

double Point2d::distance(const Point2d& p1, const Point2d& p2)
{
    return p1.distance(p2);
}

//return the orientation of the points. the orientation is colinear if when looking at b from a, c is straight ahead, clockwise if c is to the right of b, and counterclockwise if c is to the left of b
Orientation Point2d::orientation(const Point2d& a, const Point2d& b, const Point2d& c)
{
    double val = (b.getY() - a.getY()) * (c.getX() - b.getX()) -
                 (b.getX() - a.getX()) * (c.getY() - b.getY());
    if (val == 0) return Orientation::COLINEAR; 
    return (val > 0) ? Orientation::CLOCKWISE : Orientation::COUNTERCLOCKWISE;  
}

// Getters
double Point2d::getY() const
{
    return m_y;
}

double Point2d::getX() const
{
    return m_x;
}

// Setters. you could also add limitataions like if you want it to be limited to like a certian range or smth
void Point2d::setY(double y)
{
    m_y = y;
}

void Point2d::setX(double x)
{
    m_x = x;
}


