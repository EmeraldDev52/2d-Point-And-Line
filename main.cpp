#include <iostream>
#include <cmath>

#include <Line2d.h>
#include <Point2d.h>




int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };

    first.print();
    second.print();

    std::cout << "Distance between two points: " << Point2d::distance(first, second) << '\n';
    std::cout << "Distance between two points: " << first.distance(second) << '\n';

    return 0;
}