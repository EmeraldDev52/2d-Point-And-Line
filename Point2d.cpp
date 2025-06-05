#include "Point2d.h"
#include "OrientationEnum.h"
#include <iostream>
#include <cmath>
Point2d::Point2d(double x, double y) 
    : m_x {x}
    , m_y {y}
{}   

void Point2d::print() const
{
    std::cout << "Point2d: " << m_x << ", " << m_y << std::endl;
}

double Point2d::distance(const Point2d& p1, const Point2d& p2)
{
    return std::hypot(p1.getX() - p2.getX(), p1.getY() - p2.getY());
}

double Point2d::distance(const Point2d& p2)
{
    return std::hypot(m_x - p2.getX(), m_y - p2.getY());
}

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

// Setters. you could also add limitataions like if  you want it to be limited to like a certian range or smth
void Point2d::setY(double y)
{
    m_y = y;
}

void Point2d::setX(double x)
{
    m_x = x;
}
