#pragma once
#include "orientationEnum.h"



namespace Geo2d{
    // Vector2d struct
    class Vector2d
    {
    public:
        double x{0.0};
        double y{0.0};

        

        Vector2d() = default;// default constructor
        Vector2d(double x, double y);// constructor


        //operator overloads
        Vector2d operator+(const Vector2d& other) const;
        Vector2d operator-(const Vector2d& other) const;
        Vector2d operator*(double scalar) const;
        Vector2d operator/(double scalar) const;
        bool operator==(const Vector2d& other) const;
        bool operator!=(const Vector2d& other) const;


        // returns the distance between two vectors
        double distance(const Vector2d& v2) const;


        double magnitude() const;// returns the magnitude(length) of the vector


        Vector2d normalized() const;// returns the normalized vector


        void print() const;// prints the position of the vector





        //CONSTS
        static const Vector2d ZERO;
        static const Vector2d UP;
        static const Vector2d DOWN;
        static const Vector2d LEFT;
        static const Vector2d RIGHT;
    };
}
