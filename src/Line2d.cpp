#include "../include/Geo2d/Line2d.h"
#include <iostream> 
#include <optional> 
#include "../include/Geo2d/Vector2d.h"




namespace Geo2d{
    // Constructor
    Line2d::Line2d(const Vector2d& start, const Vector2d& end)
        : m_start{start}
        , m_end{end}
    {
        if (start == end) {
            throw std::invalid_argument("Line2d must have distinct start and end points");
        }
    }


    // checks if two lines intersect
    std::optional<Vector2d> Line2d::intersects(const Line2d& other) const {
        const Vector2d& p = m_start;
        const Vector2d  r = m_end - m_start;

        const Vector2d& q = other.m_start;
        const Vector2d  s = other.m_end - other.m_start;

        double r_cross_s = r.cross(s);
        Vector2d q_minus_p = q - p;
        double q_p_cross_r = q_minus_p.cross(r);


        if (std::abs(r_cross_s) < 1e-10) {
            return std::nullopt;
        }

        double t = q_minus_p.cross(s) / r_cross_s;
        double u = q_minus_p.cross(r) / r_cross_s;

        if (t >= 0.0 && t <= 1.0 && u >= 0.0 && u <= 1.0) {
            return p + r * t;
        }

        return std::nullopt;
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
    void Line2d::setStart(const Vector2d& start) {
        if (start == m_end) {
            throw std::invalid_argument("Start point cannot be the same as the end point");
        }
        m_start = start;
    }
    // setter for end point
    void Line2d::setEnd(const Vector2d& end) {
        if (end == m_start) {
            throw std::invalid_argument("Start point cannot be the same as the end point");
        }
        m_end = end;
    }
}