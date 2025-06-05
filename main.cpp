#include <iostream>
#include <cassert>
#include "Point2d.h"
#include "Vector2d.h"
#include "Line2d.h"
#include "BoundingBox.h"
#include "Polygon.h"

int main() {
    // ---- Point2d Tests ----
    Point2d p0;
    Point2d p1(0, 0);
    Point2d p2(1e9, -1e9);
    Point2d p3(-1e-9, 1e-9);
    assert(p1 == p0);
    assert((p2 - p2) == p0);
    p1.print();
    p2.print();
    p3.print();

    // ---- Vector2d Tests ----
    Vector2d v1(3, 4);
    Vector2d v2(0, 0);
    assert(Vector2d::distance(v1, v2) == 5);
    assert(v1.distance(v2) == 5);
    v1.print();
    (v1 + v1).print();

    // ---- Line2d Tests ----
    Line2d line1(Point2d(0, 0), Point2d(1, 1));
    Line2d line2(Point2d(0, 1), Point2d(1, 0));
    Line2d line3(Point2d(0, 0), Point2d(0, 1));
    Line2d line4(Point2d(1, 0), Point2d(1, 1));
    assert(line1.intersects(line2).has_value()); // should intersect diagonally
    assert(!line3.intersects(line4).has_value()); // vertical lines not touching
    try {
        Line2d badLine(Point2d(1, 1), Point2d(1, 1));
        assert(false); // Should not reach
    } catch (const std::invalid_argument&) {
        std::cout << "Caught expected Line2d exception.\n";
    }

    // ---- BoundingBox Tests ----
    BoundingBox box1(Point2d(0, 10), Point2d(10, 0));
    BoundingBox box2(Point2d(5, 15), Point2d(15, 5));
    BoundingBox box3(Point2d(20, 30), Point2d(30, 20));
    BoundingBox box4(Point2d(10, 10), Point2d(20, 0)); // Touches box1 on right edge
    assert(box1.intersects(box2));
    assert(!box1.intersects(box3));
    assert(box1.intersects(box4)); // Edge touching is still intersection by your logic

    // ---- Polygon Tests ----
    Polygon square1(4, 10, Point2d(0, 0)); // Square around origin
    Polygon square2(4, 10, Point2d(5, 0)); // Overlaps with square1
    Polygon square3(4, 10, Point2d(100, 100)); // Far away
    Polygon tiny(4, 0.1, Point2d(0, 0)); // Completely inside square1
    assert(square1.overlaps(square2));
    assert(!square1.overlaps(square3));
    assert(square1.overlaps(tiny)); // Should detect bounding box containment

    // Check line segment intersection in polygons (edge-edge overlap)
    Polygon triangle1(3, 10, Point2d(0, 0));
    Polygon triangle2(3, 10, Point2d(0, 0));

    std::vector<Point2d> flippedPoints;
    for (const auto& pt : triangle1.getVertices()) {
        flippedPoints.push_back(Point2d(-pt.m_x, -pt.m_y));
    }

    std::cout << "Flipped triangle vertices:\n";
    for (const auto& pt : flippedPoints) {
        pt.print();
    }


    std::cout << "passed.\n";
    return 0;
}
