#pragma once
#include "orientationEnum.h"



namespace Geo2d{
    // Vector2d struct
    struct Vector2d
    {
        double m_x{0.0};
        double m_y{0.0};

        
        Vector2d() = default;

        Vector2d(double x, double y);
        Vector2d operator+(const Vector2d& other) const;
        Vector2d operator-(const Vector2d& other) const;

        double magnitude() const;

        Vector2d normalized() const;

        void print() const;

        //CONSTS
        static const Vector2d ZERO;
        static const Vector2d UP;
        static const Vector2d DOWN;
        static const Vector2d LEFT;
        static const Vector2d RIGHT;
    };
}