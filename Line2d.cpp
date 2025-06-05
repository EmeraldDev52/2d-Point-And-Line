#include "Line2d.h"
#include "Point2d.h"
#include "OrientationEnum.h"
#include <iostream>
Line2d::Line2d(const Point2d& start, const Point2d& end)
    : m_start(start)
    , m_end(end) 
{}

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
static bool intersects(const Line2d& line1, const Line2d& line2)
{
    Point2d A = line1.getStart(), B = line1.getEnd();
    Point2d C = line2.getStart(), D = line2.getEnd();

    Orientation o1 = Point2d::orientation(A, B, C);
    Orientation o2 = Point2d::orientation(A, B, D);
    Orientation o3 = Point2d::orientation(C, D, A);
    Orientation o4 = Point2d::orientation(C, D, B);

    return (o1 != o2 && o3 != o4);
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
void Line2d::setLine(const Point2d& start, const Point2d& end)
{
    m_start = start;
    m_end = end;
}
void Line2d::print()
{
    std::cout << "Line2d: Start(" << m_start.getX() << ", " << m_start.getY() << "), End(" << m_end.getX() << ", " << m_end.getY() << ")\n";
}
