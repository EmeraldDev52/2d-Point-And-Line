#include "../include/Geo2d/Line2d.h"
#include <iostream> 
#include <optional> 
#include "../include/Geo2d/Point2d.h"
#include "../include/Geo2d/Vector2d.h"



namespace Geo2d{
    // Constructor
    Line2d::Line2d(const Point2d& start, const Point2d& end)
        : m_start{start}
        , m_end{end}
    {
        if (start == end) {
            throw std::invalid_argument("Line2d must have distinct start and end points");
        }
    }


    // checks if two lines intersect
    std::optional<Point2d> Line2d::intersects(const Line2d& other) const
    {
        const Point2d& A = m_start;
        const Point2d& B = m_end;
        const Point2d& C = other.m_start;
        const Point2d& D = other.m_end;

        // Orientation function
        auto orientation = [](const Point2d& a, const Point2d& b, const Point2d& c) -> Orientation {
            double val = (b.y - a.y) * (c.x - b.x) -
                        (b.x - a.x) * (c.y - b.y);

            if (val == 0.0) return Orientation::COLINEAR;
            return (val > 0.0) ? Orientation::CLOCKWISE : Orientation::COUNTERCLOCKWISE;
        };

        // orientation of the triples of points
        Orientation o1 = orientation(A, B, C);
        Orientation o2 = orientation(A, B, D);
        Orientation o3 = orientation(C, D, A);
        Orientation o4 = orientation(C, D, B);

        // general case: lines intersect if orientations differ
        if (o1 != o2 && o3 != o4) {
            // calculate actual intersection point using line-line intersection math
            double x1 = A.x, y1 = A.y;
            double x2 = B.x, y2 = B.y;
            double x3 = C.x, y3 = C.y;
            double x4 = D.x, y4 = D.y;

            double denom = (x1 - x2) * (y3 - y4) - 
                        (y1 - y2) * (x3 - x4);

            if (denom == 0.0){
                return std::nullopt; // should not happen if orientations already differ but could due to floating point precision issues
            }

            double px = ((x1 * y2 - y1 * x2) * (x3 - x4) -
                        (x1 - x2) * (x3 * y4 - y3 * x4)) / denom;

            double py = ((x1 * y2 - y1 * x2) * (y3 - y4) -
                        (y1 - y2) * (x3 * y4 - y3 * x4)) / denom;

            return Point2d(px, py);
        }

        // no intersection
        return std::nullopt;
    }
    // static method to check if two lines intersect
    std::optional<Point2d> Line2d::intersects(const Line2d& line1, const Line2d& line2) {
        return line1.intersects(line2);
    }
        

    // prints the points of the line
    void Line2d::print() const {
        std::cout << "Line2d: Start(" << m_start.x << ", " << m_start.y << "), End(" << m_end.x << ", " << m_end.y << ")\n";
    }


    // return the direction of the line as a Vector2d
    Vector2d Line2d::getDirection() const {
        return Vector2d(m_end.x - m_start.x, m_end.y - m_start.y);
    }


    // returns the length of the line
    double Line2d::length() const {
        return m_start.distance(m_end);
    }


    // setter for start point
    void Line2d::setStart(const Point2d& start) {
        if (start == m_end) {
            throw std::invalid_argument("Start point cannot be the same as the end point");
        }
        m_start = start;
    }
    // setter for end point
    void Line2d::setEnd(const Point2d& end) {
        if (end == m_start) {
            throw std::invalid_argument("Start point cannot be the same as the end point");
        }
        m_end = end;
    }
}