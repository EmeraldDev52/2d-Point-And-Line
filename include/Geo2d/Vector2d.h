#pragma once
#include <stdexcept>

namespace Geo2d{
    // Vector2d struct
    class Vector2d
    {
    public:
        double x{0.0};
        double y{0.0};

        

        Vector2d() = default;// default constructor
        Vector2d(double x, double y) : x(x), y(y) {}// constructor


        //operator overloads
        inline Vector2d operator+(const Vector2d& other) const { return Vector2d(x + other.x, y + other.y); }
        inline Vector2d operator-(const Vector2d& other) const { return Vector2d(x - other.x, y - other.y); }


        inline Vector2d operator*(double scalar) const { return Vector2d(x * scalar, y * scalar); }
        inline friend Vector2d operator*(double s, const Vector2d& v) { return Vector2d(v.x * s, v.y * s); }


        inline Vector2d operator/(double scalar) const {
            if (scalar == 0.0) throw std::invalid_argument("Division by zero");

            return Vector2d(x / scalar, y / scalar); 
        }
        inline friend Vector2d operator/(double scalar, const Vector2d& v) {
            constexpr double epsilon = 1e-8;
            if (std::abs(v.x) < epsilon || std::abs(v.y) < epsilon)
                throw std::invalid_argument("Division by zero component in vector");

            return Vector2d(scalar / v.x, scalar / v.y); 
        }


        inline bool operator==(const Vector2d& other) const {
            constexpr double epsilon = 1e-8;
            return std::abs(x - other.x) < epsilon && std::abs(y - other.y) < epsilon;
        }
        inline bool operator!=(const Vector2d& other) const { return !(*this == other); }


        double distance(const Vector2d& other) const;// returns the distance between two vectors


        double dot(const Vector2d& other) const;// returns the dot product of two vectors


        double cross(const Vector2d& other) const;// returns the cross product of two vectors


        double angleBetween(const Vector2d& other) const;// static method that returns the angle between two vectors


        double magnitude() const;// returns the magnitude(length) of the vector


        Vector2d normalized() const;// returns the normalized vector


        void print() const;// prints the position of the vector





        //CONSTS
        static const Vector2d ZERO;
        static const Vector2d UP;
        static const Vector2d DOWN;
        static const Vector2d LEFT;
        static const Vector2d RIGHT;
        static const Vector2d ONE;
    };
}
