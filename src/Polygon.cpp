#include "../include/Geo2d/Polygon.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>
#include "../include/Geo2d/Point2d.h"
#include "../include/Geo2d/Line2d.h"
#include "../include/Geo2d/Line2d.h"



namespace Geo2d{
    //constructor
    Polygon::Polygon(int sides, double radius, Point2d origin)
    {
        if (sides < 3) throw std::invalid_argument("Polygon must have at least 3 sides.");

        const double angleStep = 2 * M_PI / sides;

        for (int i = 0; i < sides; ++i)
        {
            double angle = i * angleStep;
            double x = radius * std::cos(angle);
            double y = radius * std::sin(angle);
            m_vertices.push_back(origin + Point2d(x, y));
        }
    }


    //prints the vertices of the polygon
    void Polygon::print() const
    {
        std::cout << "Regular Polygon with " << m_vertices.size() << " sides:\n";
        for (const auto& pt : m_vertices)
        {
            pt.print();
        }
    }


    //return the vertices of the polygon
    std::vector<Point2d> Polygon::getVertices() const
    {
        return m_vertices;
    }


    //return the lines of the polygon
    std::vector<Line2d> Polygon::getLines() const
    {
        std::vector<Line2d> lines;
        size_t n = m_vertices.size();

        // loops through the vertices and returns the lines between adjascent vertices
        for (size_t i = 0; i < n; ++i)
        {
            const Point2d& start = m_vertices[i];
            const Point2d& end = m_vertices[(i + 1) % n];
            lines.emplace_back(start, end);
        }

        return lines;
    }


    // checks if two polygons overlap
    bool Polygon::overlaps(const Polygon& other) const
    {
        if(!getBoundingBox().intersects(other.getBoundingBox())) return false;

        auto lines1 = getLines();
        auto lines2 = other.getLines();
        for (const auto& line1 : lines1)
        {
            for (const auto& line2 : lines2)
            {
                if (line1.intersects(line2).has_value())
                {
                    return true;
                }

            }
        }
        return false;
    }
    // static method to check if two polygons overlap
    bool Polygon::overlaps(const Polygon& poly1, const Polygon& poly2)
    {
        return poly1.overlaps(poly2);
    }


    // returns the bounding box of the polygon
    BoundingBox Polygon::getBoundingBox() const
    {
        const auto& verts = getVertices();

        double minX = verts[0].x;
        double maxX = verts[0].x;
        double minY = verts[0].y;
        double maxY = verts[0].y;

        for (const auto& p : verts)
        {
            if (p.x < minX) minX = p.x;
            if (p.x > maxX) maxX = p.x;
            if (p.y < minY) minY = p.y;
            if (p.y > maxY) maxY = p.y;
        }

        return BoundingBox(Point2d(minX, maxY), Point2d(maxX, minY));
    }
}