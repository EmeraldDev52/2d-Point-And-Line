//#pragma once
//
//namespace Geo2d{
//    // Point2d class
//    struct Point2d {
//        double x{0.0};
//        double y{0.0};
//
//
//        Point2d() = default;// default constructor
//        Point2d(double x, double y);// constructor
//
//
//        // operator overloads
//        Point2d operator+(const Point2d& other) const;
//        Point2d operator-(const Point2d& other) const;
//        bool operator==(const Point2d& other) const;
//
//
//        //
//        double distance(const Point2d& p2) const;// returns the distance between two points
//        static double distance(const Point2d& p1, const Point2d& p2);// static method that returns the distance between two points
//
//
//        void print() const;// prints the position of the point
//
//
//
//
//
//        //CONSTS
//        static const Point2d ZERO;
//    };
//}