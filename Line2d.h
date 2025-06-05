#pragma once

#include "Point2d.h"
#include "Vector2d.h"
#include <optional>
//line2d class
class Line2d
{
private:
    Point2d m_start{0, 0};
    Point2d m_end{0, 0};
public:

    
    Line2d(const Point2d& start, const Point2d& end);

    std::optional<Point2d> intersects(const Line2d& other) const;
    static std::optional<Point2d> intersects(const Line2d& line1, const Line2d& line2);

    const Point2d& getStart() const { return m_start; }
    const Point2d& getEnd() const { return m_end; }
    

    Vector2d getDirection() const;

    void print() const;

    
};