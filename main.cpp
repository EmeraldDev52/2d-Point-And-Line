#include <iostream>
#include <cassert>
#include "Point2d.h"
#include "Vector2d.h"
#include "Line2d.h"
#include "BoundingBox.h"
#include "Polygon.h"

int main() {
    Vector2d v1(3.11, 4.43);
    Vector2d v2(1.24, 2.1);
    Vector2d v3 = v1 + v2;
    v1.print();
    v2.print();
    v3.print();
    std::cout << "Magnitude of v1: " << v1.magnitude() << std::endl;
    std::cout << "Magnitude of v2: " << v2.magnitude() << std::endl;
    std::cout << "Magnitude of v3: " << v3.magnitude() << std::endl;
    std::cout << "v1 normalized: " << std::endl;
    v1.normalized().print();
    std::cout << "v2 normalized: " << std::endl;
    v2.normalized().print();
    std::cout << "v3 normalized: " << std::endl;
    v3.normalized().print();
    Line2d line1(Point2d(0, 0), Point2d(4, 4));
    std::cout << line1.length() << std::endl;
    std::cin.get();
}
