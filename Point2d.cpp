#include "Point2d.h"
#include <iostream>
Point2d::Point2d(double x, double y)
    : m_x(x)
    , m_y(y) 
{}

Point2d Point2d::operator+(const Point2d& other) const {
    return Point2d(m_x + other.m_x, m_y + other.m_y); 
}
Point2d Point2d::operator-(const Point2d& other) const {
    return Point2d(m_x - other.m_x, m_y - other.m_y); 
}
bool Point2d::operator==(const Point2d& other) const {
    return m_x == other.m_x && m_y == other.m_y;
}

void Point2d::print() const {
    std::cout << "Point2d: (" << m_x << ", " << m_y << ")\n";
}