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
    return Point2d(this->m_x + other.m_x, this->m_y + other.m_y);
}

// prints the position of the points
void Point2d::print() const
{
    std::cout << "Point2d: " << m_x << ", " << m_y << std::endl;
}

//gets the distance between two points
double Point2d::distance(const Point2d& p2) const
{
    return std::hypot(m_x - p2.m_x, m_y - p2.m_y);
}

double Point2d::distance(const Point2d& p1, const Point2d& p2)
{
    return p1.distance(p2);
}

//return the orientation of the points. the orientation is colinear if when looking at b from a, c is straight ahead, clockwise if c is to the right of b, and counterclockwise if c is to the left of b
Orientation Point2d::orientation(const Point2d& a, const Point2d& b, const Point2d& c)
{
    double val = (b.m_y - a.m_y) * (c.m_x - b.m_x) -
                 (b.m_x - a.m_x) * (c.m_y - b.m_y);
    if (val == 0) return Orientation::COLINEAR; 
    return (val > 0) ? Orientation::CLOCKWISE : Orientation::COUNTERCLOCKWISE;  
}



