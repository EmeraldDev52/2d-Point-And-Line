#include "../include/Geo2d/Point2d.h"
#include <iostream>
#include <cmath>
namespace Geo2d{

    // constructor
    Point2d::Point2d(double x, double y)
        : x{x}
        , y{y} 
    {}

    
    // operator overloads
    Point2d Point2d::operator+(const Point2d& other) const {
        return Point2d(x + other.x, y + other.y); 
    }
    Point2d Point2d::operator-(const Point2d& other) const {
        return Point2d(x - other.x, y - other.y); 
    }
    bool Point2d::operator==(const Point2d& other) const {
        return x == other.x && y == other.y;
    }


    // prints the position of the point
    void Point2d::print() const {
        std::cout << "Point2d: (" << x << ", " << y << ")\n";
    }


    // returns the distance between two points
    double Point2d::distance(const Point2d& p2) const{
        return std::hypot(this->x - p2.x, this->y - p2.y);    
    }
    // static method that returns the distance between two points
    double Point2d::distance(const Point2d& p1, const Point2d& p2){
        return p1.distance(p2);
    }





    // CONSTS
    const Point2d Point2d::ZERO = Point2d(0.0, 0.0);
}