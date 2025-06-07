#pragma once

#include "Vector2d.h"



namespace Geo2d{
    // BoundingBox struct
    struct BoundingBox
    {
        Vector2d topLeft, bottomRight;


        BoundingBox(Vector2d tl, Vector2d br);// constructor


        bool intersects(const BoundingBox& other) const;// checks if 2 bounding boxes overlap
        static bool intersects(const BoundingBox& box1, const BoundingBox& box2);// static method to check if two bounding boxes overlap
    };
}