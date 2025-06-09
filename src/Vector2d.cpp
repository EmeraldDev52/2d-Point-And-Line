#include "../include/Geo2d/Vector2d.h"
#include "../include/Geo2d/OrientationEnum.h"
#include <iostream>
#include <cmath>



namespace Geo2d{
    //constructor
    Vector2d::Vector2d(double x, double y) 
        : x{x}
        , y{y}
    {}   


    //operator overloads
    Vector2d Vector2d::operator+(const Vector2d& other) const {
        return Vector2d(this->x + other.x, this->y + other.y);
    }
    Vector2d Vector2d::operator-(const Vector2d& other) const{
        return Vector2d(this->x - other.x, this->y - other.y);
    }
    Vector2d Vector2d::operator*(double scalar) const{
        return Vector2d(this->x * scalar, this->y * scalar);
    }
    Vector2d Vector2d::operator/(double scalar) const{
        if (scalar == 0.0) {
            throw std::invalid_argument("Division by zero is not allowed.");
        }
        return Vector2d(this->x / scalar, this->y / scalar);
    }
    bool Vector2d::operator==(const Vector2d& other) const{
        return ((this->x == other.x) && (this->y == other.y));
    }
    bool Vector2d::operator!=(const Vector2d& other) const{
        return !(*this == other); 
    }


    // returns the distance between two vectors
    double Vector2d::distance(const Vector2d& other) const {
        return std::hypot(this->x - other.x, this->y - other.y);
    }
    // static method that returns the distance between two vectors
    double Vector2d::distance(const Vector2d& v1, const Vector2d& v2) {
        return v1.distance(v2);
    }


    // returns the dot product of two vectors
    double Vector2d::dot(const Vector2d& other) const {
        return this->x * other.x + this->y * other.y;
    }
    // static method that returns the dot product of two vectors 
    double Vector2d::dot(const Vector2d& v1, const Vector2d& v2) {
        return v1.dot(v2);
    }


    // returns the cross product of two vectors
    double Vector2d::cross(const Vector2d& other) const {
        return this->x * other.y - this->y * other.x;
    }
    // static method that returns the cross product of the two vectors
    double Vector2d::cross(const Vector2d& v1, const Vector2d& v2) {
        return v1.cross(v2);
    }


    // returns the angle between two vectors IN RADIANS
    double Vector2d::angleBetween(const Vector2d& other) const {
        double dotProd = this->dot(other);
        double magProduct = this->magnitude() * other.magnitude();

        // Protect against division by zero or floating point errors
        if (magProduct == 0) return 0.0;

        double cosTheta = dotProd / magProduct;

        // Clamp value between -1 and 1 to avoid errors
        if (cosTheta > 1.0) cosTheta = 1.0;
        if (cosTheta < -1.0) cosTheta = -1.0;

        return std::acos(cosTheta); // returns angle in radians
    }
    // static method that returns the angle between two vectors
    double Vector2d::angleBetween(const Vector2d& v1, const Vector2d& v2) {
        return v1.angleBetween(v2);
    }


    // prints the position of the points
    void Vector2d::print() const{ 
        std::cout << "Vector2d: " << this->x << ", " << this->y << std::endl;
    }


    // returns the magnitude of the vector
    double Vector2d::magnitude() const {
        return std::hypot(this->x, this->y);
    }


    // returns the normalized vector
    Vector2d Vector2d::normalized() const{
        double mag = this->magnitude();
        if (mag == 0.0) return Vector2d(0, 0); // Avoid division by zero
        return Vector2d(x / mag, y / mag);
    }





    //CONSTS
    constexpr Vector2d Vector2d::ZERO = Vector2d(0.0, 0.0);
    constexpr Vector2d Vector2d::UP = Vector2d(0.0, 1.0);
    constexpr Vector2d Vector2d::DOWN = Vector2d(0.0, -1.0);
    constexpr Vector2d Vector2d::LEFT = Vector2d(-1.0, 0.0);
    constexpr Vector2d Vector2d::RIGHT = Vector2d(1.0, 0.0);
    constexpr Vector2d Vector2d::ONE = Vector2d(1, 1);
}