#pragma once
#include "Point2d.h"
#include <vector>
#include "BoundingBox.h"
#include "Line2d.h"


class Polygon
{
private:
    std::vector<Point2d> m_vertices;

public:
    Polygon(int sides, double radius, Point2d center);
    void print() const;
    std::vector<Point2d> getVertices() const;
    std::vector<Line2d> getLines();
    bool overlaps(Polygon& other);
    static bool overlaps(Polygon& poly1, Polygon& poly2);
    BoundingBox getBoundingBox() const;
};
