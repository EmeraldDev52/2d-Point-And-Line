#pragma once

#include "Vector2d.h"



namespace Geo2d{
    // BoundingBox struct
    struct BoundingBox
    {
        Vector2d topLeft{Vector2d(0, 0)}, bottomRight{Vector2d(0, 0)};


        BoundingBox(Vector2d tl, Vector2d br);// constructor


        bool intersects(const BoundingBox& other) const;// checks if 2 bounding boxes overlap
    };
}