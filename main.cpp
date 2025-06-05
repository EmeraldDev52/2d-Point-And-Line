#include <iostream>
#include <cmath>

#include "Line2d.h"
#include "Point2d.h"




int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };
    Line2d line{ first, second };
    Line2d line2{ Point2d{3.0, 2.5}, Point2d{5.2, 6.4} };
    first.print();
    second.print();
    line.print();
    std::cout << "line one intersects line two: " << (line.intersects(line2) ? "Yes" : "No") << '\n';
    std::cout << "line one intersects line two: " << (Line2d::intersects(line, line2) ? "Yes" : "No") << '\n';

    std::cout << first.getX() << ", " << first.getY() << '\n';  
    std::cout << second.getX() << ", " << second.getY() << '\n';

    line2.print();
    first = Point2d(1.0, 2.0);
    second = Point2d(5.0, 6.0);

    first.print();
    second.print();
    first.setX(10.0);
    first.setY(20.0);
    second.setX(30.0);
    second.setY(40.0);
    first.print();
    second.print();

    std::cout << "Distance between two points: " << Point2d::distance(first, second) << '\n';
    std::cout << "Distance between two points: " << first.distance(second) << '\n';

    std::cin.get();
    return 0;
}