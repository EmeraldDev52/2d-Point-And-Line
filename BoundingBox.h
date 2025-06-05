#pragma once
#include "Point2d.h"

//BoundingBox struct
struct BoundingBox
{
    Point2d topLeft, bottomRight;

    BoundingBox(Point2d topLeft, Point2d bottomRight);

    bool intersects(const BoundingBox& other) const;
    static bool intersects(const BoundingBox& box1, const BoundingBox& box2);
};
