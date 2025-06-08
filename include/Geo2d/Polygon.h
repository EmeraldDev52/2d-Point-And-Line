#pragma once

#include "Vector2d.h"
#include <vector>
#include "BoundingBox.h"
#include "Line2d.h"



namespace Geo2d{
    //Polygon class
    class Polygon
    {
    private:
        std::vector<Vector2d> m_vertices;

    public:
        Polygon(int sides, double innerCircleRadius = 1, Vector2d origin = Vector2d::ZERO, double rotationOffset = 0);// constructor


        void print() const;// prints the vertices of the polygon


        std::vector<Vector2d> getVertices() const;// returns the vertices of the polygon
        std::vector<Line2d> getLines() const;// returns the lines between adjascent vertices of the polygon


        bool overlaps(const Polygon& other) const;// checks if two polygons overlap
        static bool overlaps(const Polygon& poly1, const Polygon& poly2);// static method to check if two polygons overlap


        bool contains(const Vector2d& point) const;// checks if a point is inside the 


        double area() const; // returns the area of the polygon


        Vector2d centroid() const;// returns the centroid (basically the center of mass) of the polygon

        
        BoundingBox getBoundingBox() const;// returns the bounding box of the polygon
    };
}