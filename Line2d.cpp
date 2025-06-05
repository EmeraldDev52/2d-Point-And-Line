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
    Point2d C = other.getStart(), D = other.getEnd();

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
    

//Getters
Point2d Line2d::getStart() const
{
    return m_start;
}
Point2d Line2d::getEnd() const
{
    return m_end;
}

// Setters. you could also add limitations here if you want to
void Line2d::setStart(const Point2d& start)
{
    m_start = start;
}
void Line2d::setEnd(const Point2d& end)
{
    m_end = end;
}

//prints the points of the line
void Line2d::print() const
{
    std::cout << "Line2d: Start(" << m_start.getX() << ", " << m_start.getY() << "), End(" << m_end.getX() << ", " << m_end.getY() << ")\n";
}
