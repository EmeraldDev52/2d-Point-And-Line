#pragma once
// Point2d class
struct Point2d {
    double m_x = 0.0;
    double m_y = 0.0;

    Point2d() = default;
    Point2d(double x, double y);

    Point2d operator+(const Point2d& other) const;
    Point2d operator-(const Point2d& other) const;
    bool operator==(const Point2d& other) const;

    void print() const;
};
