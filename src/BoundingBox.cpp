#include "../include/Geo2d/BoundingBox.h"
#include "../include/Geo2d/Vector2d.h"
#include <iostream>



namespace Geo2d{
    // constructor
    BoundingBox::BoundingBox(Vector2d tl, Vector2d br)
        : topLeft{tl}
        , bottomRight{br}
    {
        if (tl.x > br.x || tl.y < br.y) {
            throw std::invalid_argument("Top left must be higher and further left than bottom right");
        }
    }


    // checks if 2 bounding boxes overlap
    bool BoundingBox::intersects(const BoundingBox& other) const {
        if (bottomRight.x < other.topLeft.x ||  // this box is left of other
            topLeft.x > other.bottomRight.x ||  // this box is right of other
            topLeft.y < other.bottomRight.y ||  // this box is below other 
            bottomRight.y > other.topLeft.y     // this box is above other
        ) { return false; }

        return true;
    }
}