#pragma once

#include "Vector2d.h"
#include <optional>



namespace Geo2d{
    //line2d class
    class Line2d
    {
    private:
        Vector2d m_start{0, 0};
        Vector2d m_end{0, 0};
    public:
        Line2d(const Vector2d& start, const Vector2d& end);// constructor


        std::optional<Vector2d> intersects(const Line2d& other) const;// checks if two lines intersect
        static std::optional<Vector2d> intersects(const Line2d& line1, const Line2d& line2);// static method to check if two lines intersect


        Vector2d getStart() const { return m_start; }// getter for start point
        Vector2d getEnd() const { return m_end; }// getter for end point


        void setStart(const Vector2d& start);// setter for start point
        void setEnd(const Vector2d& end);// setter for end point
        

        Vector2d getDirection() const;// returns the direction of the line as a Vector2d
        double length() const;// returns the length of the line


        void print() const;// prints the points of the line
    };
}