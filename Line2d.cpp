#include "Line2d.h"
#include <iostream> 
#include <optional> 
#include "Point2d.h"
#include "Vector2d.h"

// Constructor
Line2d::Line2d(const Point2d& start, const Point2d& end)
    : m_start(start)
    , m_end(end)
{
    if (start == end) {
        throw std::invalid_argument("Line2d must have distinct start and end points");
    }
}



// Checks if two lines intersect
std::optional<Point2d> Line2d::intersects(const Line2d& other) const
{
    const Point2d& A = m_start;
    const Point2d& B = m_end;
    const Point2d& C = other.m_start;
    const Point2d& D = other.m_end;

    // Orientation function
    auto orientation = [](const Point2d& a, const Point2d& b, const Point2d& c) -> Orientation {
        double val = (b.m_y - a.m_y) * (c.m_x - b.m_x) -
                     (b.m_x - a.m_x) * (c.m_y - b.m_y);

        if (val == 0.0) return Orientation::COLINEAR;
        return (val > 0.0) ? Orientation::CLOCKWISE : Orientation::COUNTERCLOCKWISE;
    };

    Orientation o1 = orientation(A, B, C);
    Orientation o2 = orientation(A, B, D);
    Orientation o3 = orientation(C, D, A);
    Orientation o4 = orientation(C, D, B);

    // General case: lines intersect if orientations differ
    if (o1 != o2 && o3 != o4) {
        // Calculate actual intersection point using line-line intersection math
        double x1 = A.m_x, y1 = A.m_y;
        double x2 = B.m_x, y2 = B.m_y;
        double x3 = C.m_x, y3 = C.m_y;
        double x4 = D.m_x, y4 = D.m_y;

        double denom = (x1 - x2) * (y3 - y4) - 
                       (y1 - y2) * (x3 - x4);

        if (denom == 0.0){
            return std::nullopt; // should not happen if orientations already differ
        }

        double px = ((x1 * y2 - y1 * x2) * (x3 - x4) -
                     (x1 - x2) * (x3 * y4 - y3 * x4)) / denom;

        double py = ((x1 * y2 - y1 * x2) * (y3 - y4) -
                     (y1 - y2) * (x3 * y4 - y3 * x4)) / denom;

        return Point2d{px, py};
    }

    // No intersection
    return std::nullopt;
}


std::optional<Point2d> Line2d::intersects(const Line2d& line1, const Line2d& line2)
{
    return line1.intersects(line2);
}
    

//prints the points of the line
void Line2d::print() const
{
    std::cout << "Line2d: Start(" << m_start.m_x << ", " << m_start.m_y << "), End(" << m_end.m_x << ", " << m_end.m_y << ")\n";
}

Vector2d Line2d::getDirection() const
{
    return Vector2d(m_end.m_x - m_start.m_x, m_end.m_y - m_start.m_y);
}
double Line2d::length() const
{
    return m_start.distance(m_end);
}
void Line2d::setStart(const Point2d& start){
    if (start == m_end) {
        throw std::invalid_argument("Start point cannot be the same as the end point");
    }
    m_start = start;
}
void Line2d::setEnd(const Point2d& end){
    if (end == m_start) {
        throw std::invalid_argument("Start point cannot be the same as the end point");
    }
    m_end = end;
}
