#include "Line2d.h"
#include "Point2d.h"
#include "OrientationEnum.h"
#include <iostream>


// Constructor
Line2d::Line2d(const Point2d& start, const Point2d& end)
    : m_start(start)
    , m_end(end) 
{}


// Checks if two lines intersect
bool Line2d::intersects(const Line2d& other) const
{
    Point2d A = m_start, B = m_end;
    Point2d C = other.m_start, D = other.m_end;

    Orientation o1 = Point2d::orientation(A, B, C);
    Orientation o2 = Point2d::orientation(A, B, D);
    Orientation o3 = Point2d::orientation(C, D, A);
    Orientation o4 = Point2d::orientation(C, D, B);

    return (o1 != o2 && o3 != o4);
}
bool Line2d::intersects(const Line2d& line1, const Line2d& line2)
{
    return line1.intersects(line2);
}
    

//prints the points of the line
void Line2d::print() const
{
    std::cout << "Line2d: Start(" << m_start.m_x << ", " << m_start.m_y << "), End(" << m_end.m_x << ", " << m_end.m_y << ")\n";
}
