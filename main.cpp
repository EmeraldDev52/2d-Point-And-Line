#include <iostream>
#include <cmath>

#include "Line2d.h"
#include "Point2d.h"
#include "Polygon.h"
#include "BoundingBox.h"
#include <iterator>
#include <algorithm>


int main()
{
    Polygon polygon1(5, 10.0, Point2d(1, 2));
    Polygon polygon2(6, 5.0, Point2d(2, -1.4));

    polygon1.print();

    std::cout << std::endl;

    polygon2.print();

    std::cout << std::endl;

    std::cout << "Polygons overlap:  " << (Polygon::overlaps(polygon1, polygon2) ? "Yes" : "No") << std::endl;

    std::cout << std::endl;
    
    BoundingBox polygon1Box = polygon1.getBoundingBox();
    BoundingBox polygon2Box = polygon2.getBoundingBox();
    
    std::cout << std::endl;
    
    std::cout << "Bounding Box of polygon1: " << polygon1Box.minX << ", " << polygon1Box.maxX << polygon1Box.minY <<polygon1Box.maxY << std::endl;
    std::cout << "Bounding Box of polygon2: " << polygon2Box.minX << ", " << polygon2Box.maxX << polygon2Box.minY <<polygon2Box.maxY << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "polygon1 vertices: ";
    for (auto& pt : polygon1.getVertices())
    {
        pt.print();
    }

    std::cout << std::endl;
    
    std::cout << "polygon1 lines: \n";
    for (auto& ln : polygon1.getLines())
    {
        ln.print();
    }
    
    std::cout << std::endl;
    
    std::cout << "polygon2 vertices: \n";
    for (auto& pt : polygon2.getVertices())
    {
        pt.print();
    }
    
    std::cout << std::endl;
    
    std::cout << "polygon2 lines: \n";
    for (auto& ln : polygon2.getLines())
    {
        ln.print();
    }
    
    std::cout << std::endl;
    
    std::cin.get();
    return 0;
}