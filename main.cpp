#include <cassert>
#include <cmath>
#include <iostream>
#include "Point2d.h"
#include "Line2d.h"
#include "Polygon.h"
#include "BoundingBox.h"

int main() {
    // Point2d edge cases
    Point2d zero(0, 0);
    Point2d big(1e9, -1e9);
    Point2d close(1e-9, 1e-9);

    assert(Point2d::distance(zero, zero) == 0);
    assert(std::abs(Point2d::distance(zero, big) - std::hypot(1e9, 1e9)) < 1e-2);
    assert(std::abs(Point2d::distance(zero, close) - std::sqrt(2e-18)) < 1e-12);

    // Operator+
    Point2d p1(1, 2), p2(-1, -3);
    Point2d sum = p1 + p2;
    assert(sum.getX() == 0);
    assert(sum.getY() == -1);

    // Lines
    Line2d l1(Point2d(0, 0), Point2d(1, 1));
    Line2d l2(Point2d(1, 0), Point2d(0, 1));
    Line2d l3(Point2d(0, 0), Point2d(1, 0)); // horizontal
    Line2d l4(Point2d(0, 1), Point2d(1, 1)); // horizontal above
    Line2d l5(Point2d(0, 0), Point2d(0, 1)); // vertical
    Line2d l6(Point2d(1, 0), Point2d(1, 1)); // vertical parallel

    assert(l1.intersects(l2));      // cross
    assert(!l3.intersects(l4));     // horizontal
    assert(!l5.intersects(l6));     // vertical

    // Polygon bounding box — square
    Polygon square(4, 2, Point2d(0, 0));
    BoundingBox box = square.getBoundingBox();
    Point2d tl = Point2d(box.minX, box.maxY);
    Point2d br = Point2d(box.maxX, box.minY);
    assert(tl.getX() < br.getX());
    assert(tl.getY() > br.getY());

    // Polygon bounding box — tiny polygon
    Polygon tiny(3, 1e-6, Point2d(0, 0));
    BoundingBox tbox = tiny.getBoundingBox();
    assert(Point2d::distance(Point2d(tbox.minX, tbox.maxY), Point2d(tbox.maxX, tbox.minY)) < 1e-5);

    // Polygon overlap — nested
    Polygon bigPoly(10, 10.0, Point2d(0, 0));
    Polygon smallPoly(10, 1.0, Point2d(0, 0));
    assert(Polygon::overlaps(bigPoly, smallPoly));
    assert(Polygon::overlaps(smallPoly, bigPoly));

    // Polygon overlap — touching edges
    Polygon touch1(3, 1.0, Point2d(0, 0));
    Polygon touch2(3, 1.0, Point2d(2, 0)); // barely touch on edge
    assert(!Polygon::overlaps(touch1, touch2)); // May be false if bounding boxes don't touch

    // Polygon overlap — rotated, offset
    Polygon offsetRotated(6, 1.0, Point2d(0.5, 0.5));
    assert(Polygon::overlaps(touch1, offsetRotated));

    // Polygon overlap — far apart
    Polygon far(6, 1.0, Point2d(1000, 1000));
    assert(!Polygon::overlaps(touch1, far));

    // Degenerate polygon
    Polygon flat(3, 0.0, Point2d(0, 0));
    BoundingBox flatBox = flat.getBoundingBox();
    assert(flatBox.minX == flatBox.maxX);
    assert(flatBox.maxY == flatBox.minY);

    std::cin.get();
    return 0;
}
