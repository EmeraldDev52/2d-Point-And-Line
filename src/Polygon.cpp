#include "../include/Geo2d/Polygon.h"
#define M_PI 3.14159265358979323846
#define DEG2RAD (M_PI / 180.0)
#include <cmath>
#include <iostream>
#include "../include/Geo2d/Vector2d.h"
#include "../include/Geo2d/Line2d.h"



namespace Geo2d{
    //constructor
    Polygon::Polygon(int sides, double innerCircleRadius, Vector2d origin, double rotationOffset)
    {
        if (sides < 3) throw std::invalid_argument("Polygon must have at least 3 sides.");
        m_vertices.reserve(sides);

        double circumRadius = innerCircleRadius / std::cos(M_PI / sides);
        const double angleStep = 2 * M_PI / sides;

        for (int i = 0; i < sides; ++i)
        {
            double angle = (i * angleStep) + (M_PI / sides) - rotationOffset * DEG2RAD;
            double x = circumRadius * std::cos(angle);
            double y = circumRadius * std::sin(angle);
            m_vertices.push_back(origin + Vector2d(x, y));
        }
    }


    //prints the vertices of the polygon
    void Polygon::print() const
    {
        std::cout << "Polygon with " << m_vertices.size() << " sides:\n";
        for (const auto& pt : m_vertices)
        {
            pt.print();
        }
    }


    //return the vertices of the polygon
    std::vector<Vector2d> Polygon::getVertices() const
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
            const Vector2d& start = m_vertices[i];
            const Vector2d& end = m_vertices[(i + 1) % n];
            lines.emplace_back(start, end);
        }

        return lines;
    }


    // sets the vertices of the polygon
    // In Polygon.h & Polygon.cpp
    void Polygon::setVertices(const std::vector<Vector2d>& newVerts) {
        if (newVerts.size() < 3) throw std::invalid_argument("Polygon must have at least 3 sides.");
        m_vertices = newVerts;
    }


    // checks if two polygons overlap
    bool Polygon::overlaps(const Polygon& other) const
    {
        if(!getBoundingBox().intersects(other.getBoundingBox())) return false;
        if (this->contains(other.m_vertices[0]) || other.contains(this->m_vertices[0])) {
            return true;
        }

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

        return BoundingBox(Vector2d(minX, maxY), Vector2d(maxX, minY));
    }


    // checks if a point is inside the polygon
    bool Polygon::contains(const Vector2d& point) const {
        int intersections = 0;

        for (size_t i = 0; i < this->m_vertices.size(); ++i) {

            const Vector2d& p1 = this->m_vertices[i];
            const Vector2d& p2 = this->m_vertices[(i + 1) % this->m_vertices.size()];

            // Check if the ray intersects with the current edge
            if (((p1.y <= point.y && point.y < p2.y) || (p2.y <= point.y && point.y < p1.y)) &&
                point.x < (p2.x - p1.x) * (point.y - p1.y) / (p2.y - p1.y) + p1.x) {
                intersections++;
            }
        }

        return intersections % 2 != 0;
    }


    // returns the centroid (basically the center of mass) of the polygon
    Vector2d Polygon::centroid() const {
        int n = this->m_vertices.size();
        double cx = 0.0, cy = 0.0;
        double area = 0.0;

        for (int i = 0; i < n; ++i) {
            const Vector2d& p1 = m_vertices[i];
            const Vector2d& p2 = m_vertices[(i + 1) % n];
            double cross = p1.x * p2.y - p2.x * p1.y;

            area += cross;
            cx += (p1.x + p2.x) * cross;
            cy += (p1.y + p2.y) * cross;
        }

        area *= 0.5;
        if (area == 0) return Vector2d(); // Prevent division by zero

        cx /= (6.0 * area);
        cy /= (6.0 * area);

        return Vector2d(cx, cy);
    }


    // returns the area of the polygon
    double Polygon::area() const {
        int n = this->m_vertices.size();

        double area = 0.0;

        for (size_t i = 0; i < n; ++i) {
            const Vector2d& p1 = this->m_vertices[i];
            const Vector2d& p2 = this->m_vertices[(i + 1) % n];
            area += (p1.x * p2.y) - (p2.x * p1.y);
        }

        return std::abs(area) * 0.5;
    }
}
