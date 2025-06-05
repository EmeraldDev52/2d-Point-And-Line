#pragma once

class Line2d
{
private:
    Point2d m_start{0, 0};
    Point2d m_end{0, 0};
public:
    Line2d(const Point2d& start, const Point2d& end);

    bool intersects(const Line2d& other) const;
    static bool intersects(const Line2d& line1, const Line2d& line2);
    

    //Getters
    Point2d getStart() const;
    Point2d getEnd() const;

    // Setters. you could also add limitations here if you want to
    void setStart(const Point2d& start);
    void setEnd(const Point2d& end);

    void setLine(const Point2d& start, const Point2d& end);
};