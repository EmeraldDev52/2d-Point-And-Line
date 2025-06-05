#pragma once


//BoundingBox struct
struct BoundingBox
{
    double minX, maxX;
    double minY, maxY;

    BoundingBox(double minX, double maxX, double minY, double maxY);

    bool intersects(const BoundingBox& other) const;
    static bool intersects(const BoundingBox& box1, const BoundingBox& box2);
};
