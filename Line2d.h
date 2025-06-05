#pragma once

#include "Point2d.h"
#include "OrientationEnum.h"

//line2d class
class Line2d
{

public:
    Point2d m_start{0, 0};
    Point2d m_end{0, 0};

    
    Line2d() = default;
    
    Line2d(const Point2d& start, const Point2d& end);

    bool intersects(const Line2d& other) const;
    static bool intersects(const Line2d& line1, const Line2d& line2);
    
    void print() const;
};