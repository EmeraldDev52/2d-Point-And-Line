#pragma once
#include "orientationEnum.h"

class Point2d
{
private:

    double m_x{0.0};
    double m_y{0.0};

public:
    Point2d() = default;

    Point2d(double x, double y);
    Point2d operator+(const Point2d& other) const;
    void print() const;
    static double distance(const Point2d& p1, const Point2d& p2);
    double distance(const Point2d& p2) const;

    
    static Orientation orientation(const Point2d& a, const Point2d& b, const Point2d& c);



    double getY() const;
    double getX() const;

    void setY(double y);
    void setX(double x);
};