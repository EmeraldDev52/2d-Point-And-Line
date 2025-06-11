#include "../include/Geo2d/Polygon.h"
constexpr double M_PI = 3.14159265358979323846;
constexpr double DEG2RAD = M_PI / 180.0;
#include <cmath>
#include <iostream>
#include "../include/Geo2d/Vector2d.h"
#include "../include/Geo2d/Line2d.h"



namespace Geo2d{
    //constructor
    Polygon::Polygon(int sides, double innerCircleRadius, Vector2d origin, Vector2d scale, double rotationOffset)
    {
        if (sides < 3) throw std::invalid_argument("Polygon must have at least 3 sides.");

        m_vertices.reserve(sides);

        const double circumRadius = innerCircleRadius / std::cos(M_PI / sides);
        const double angleStep = 2 * M_PI / sides;

        for (int i = 0; i < sides; ++i)
        {
            const double angle = (i * angleStep) + (M_PI / sides) - rotationOffset * DEG2RAD;

            const double x = circumRadius * std::cos(angle) * scale.x;
            const double y = circumRadius * std::sin(angle) * scale.y;

            m_vertices.push_back(origin + Vector2d(x, y));

        }


    }

    //prints the vertices of the polygon
    void Polygon::print() const
    {
        std::cout << "Polygon with " << m_vertices.size() << " sides:\n";
        for (const Vector2d& pt : m_vertices)
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

        size_t vertCount = m_vertices.size();

        std::vector<Line2d> lines;
        lines.reserve(vertCount);


        // loops through the vertices and returns the lines between adjascent vertices
        for (size_t i = 0; i < vertCount; ++i)
        {
            const Vector2d& start = m_vertices[i];
            const Vector2d& end = m_vertices[(i + 1) % vertCount];
            lines.emplace_back(start, end);
        }

        return lines;
    }


    // sets the vertices of the polygon
    void Polygon::setVertices(const std::vector<Vector2d>& newVerts) {

        if (newVerts.size() < 3) {
            throw std::invalid_argument("Polygon must have at least 3 sides.");
        }
        m_vertices = newVerts;
    }


    // checks if two polygons overlap
    bool Polygon::overlaps(const Polygon& other) const
    {
        if(!getBoundingBox().intersects(other.getBoundingBox())) return false;

        if (this->contains(other.m_vertices[0]) || other.contains(this->m_vertices[0])) {
            return true;
        }

        const std::vector<Line2d> lines1 = getLines();
        const std::vector<Line2d> lines2= other.getLines();

        for (const Line2d& line1 : lines1)
        {
            for (const Line2d& line2 : lines2)
            {
                if (line1.intersects(line2).has_value())
                {
                    return true;
                }

            }
        }
        return false;
    }


    // returns the bounding box of the polygon
    BoundingBox Polygon::getBoundingBox() const
    {
        const std::vector<Vector2d>& verts = this->m_vertices;

        double minX = verts[0].x, maxX = verts[0].x;
        double minY = verts[0].y, maxY = verts[0].y;

        for (const Vector2d& pt : verts) {
            if (pt.x < minX) minX = pt.x;
            if (pt.x > maxX) maxX = pt.x;
            if (pt.y < minY) minY = pt.y;
            if (pt.y > maxY) maxY = pt.y;
        }

        Vector2d tl(minX, maxY);
        Vector2d br(maxX, minY);
        return BoundingBox(tl, br);

    }

    // checks if a point is inside the polygon
    bool Polygon::contains(const Vector2d& point) const {
        int intersections = 0;

        const std::vector<Vector2d>& verts = this->m_vertices;



        for (size_t i = 0; i < verts.size(); ++i) {
            Line2d edge(verts[i], verts[i++]);

            if (edge.contains(point)) {
                return true; // Point is exactly on edge
            }
        }
        for (size_t i = 0; i < verts.size(); ++i) {

            const Vector2d& p1 = verts[i];
            const Vector2d& p2 = verts[(i + 1) % verts.size()];

            // Check if the ray intersects with the current edge
            if (((p1.y <= point.y && point.y < p2.y) || (p2.y <= point.y && point.y < p1.y)) &&
                point.x < (p2.x - p1.x) * (point.y - p1.y) / (p2.y - p1.y) + p1.x) {
                intersections++;
            }
        }

        return((intersections % 2) != 0);
    }


    // returns the centroid (basically the center of mass) of the polygon
    Vector2d Polygon::centroid() const {

        const std::vector<Vector2d>& verts = this->m_vertices;

        int vertSize = verts.size();
        
        double cx = 0.0, cy = 0.0;
        double area = 0.0;

        for (size_t i = 0; i < vertSize; ++i) {
            const Vector2d& p1 = verts[i];
            const Vector2d& p2 = verts[(i + 1) % vertSize];
            const double cross = p1.x * p2.y - p2.x * p1.y;

            area += cross;
            cx += (p1.x + p2.x) * cross;
            cy += (p1.y + p2.y) * cross;
        }

        area *= 0.5;

        if (area == 0) {
            return Vector2d(); // Prevent division by zero
        }

        cx /= (6.0 * area);
        cy /= (6.0 * area);

        return Vector2d(cx, cy);
    }


    // returns the area of the polygon
    double Polygon::area() const {

        const std::vector<Vector2d>& verts = this->m_vertices;

        int vertSize = verts.size();

        double area = 0.0;

        for (size_t i = 0; i < vertSize; ++i) {

            const Vector2d& p1 = verts[i];
            const Vector2d& p2 = verts[(i + 1) % vertSize];
            area += p1.cross(p2);
        }

        return std::abs(area) * 0.5;
    }
}
