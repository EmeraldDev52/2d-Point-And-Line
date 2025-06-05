#include "Point2d.h"
#include <iostream>
#include <cmath>
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

double Point2d::distance(const Point2d& p1, const Point2d& p2){
    return p1.distance(p2);
}
double Point2d::distance(const Point2d& p2) const{
    return std::hypot(this->m_x - p2.m_x, this->m_y - p2.m_y);    
}